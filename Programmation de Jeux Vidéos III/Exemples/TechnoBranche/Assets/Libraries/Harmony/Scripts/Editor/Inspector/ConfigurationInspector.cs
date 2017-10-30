using UnityEditor;
using UnityEngine;

namespace Harmony
{
    /// <summary>
    /// Inspecteur de la configuration de Harmmony.
    /// </summary>
    [CustomEditor(typeof(Configuration), true)]
    public class ConfigurationInspector : Inspector
    {
        private Texture2D logo;

        private BasicProperty productNameProperty;
        private BasicProperty companyNameProperty;

        private EnumProperty startingScene;
        private ListProperty utilitaryScenes;

        private ListProperty tags;
        private ListProperty layers;

        private Physics2DLayerMatrixGuiProperty physics2DLayerMatrixProperty;

        [MenuItem("Harmony/Settings", priority = 100)]
        public static void OpenConfiguration()
        {
            AssetDatabase.OpenAsset(Configuration.Get());
        }

        protected override void Initialize()
        {
            logo = GetLogo();

            productNameProperty = GetProductNameProperty();
            companyNameProperty = GetCompanyNameProperty();

            startingScene = GetEnumProperty("startingScene", typeof(R.E.Scene));
            utilitaryScenes = GetListProperty("utilitaryScenes");

            tags = GetTagsProperty();
            layers = GetLayersProperty();

            physics2DLayerMatrixProperty = GetPhysics2DLayerMatrixProperty();
        }


        protected override void Draw()
        {
            DrawImage(logo);

            DrawSection("Application");
            DrawPropertyWithLabel(productNameProperty);
            DrawPropertyWithLabel(companyNameProperty);

            DrawSection("Startup");
            DrawPropertyWithLabel(startingScene);
            DrawPropertyWithLabel(utilitaryScenes);

            DrawSection("Tags and Layers");
            DrawProperty(tags);
            DrawProperty(layers);

            DrawSection("Physics");
            DrawPropertyWithTitleLabel(physics2DLayerMatrixProperty);
        }

        private Texture2D GetLogo()
        {
            return (Texture2D) AssetDatabase.LoadAssetAtPath("Assets/Libraries/Harmony/Visuals/Editor/Icons/Harmony.png", typeof(Texture2D));
        }

        private BasicProperty GetProductNameProperty()
        {
            SerializedObject serializedObject = new SerializedObject(AssetDatabase.LoadAllAssetsAtPath("ProjectSettings/ProjectSettings.asset")[0]);
            return new BasicProperty(serializedObject.FindProperty("productName"));
        }

        private BasicProperty GetCompanyNameProperty()
        {
            SerializedObject serializedObject = new SerializedObject(AssetDatabase.LoadAllAssetsAtPath("ProjectSettings/ProjectSettings.asset")[0]);
            return new BasicProperty(serializedObject.FindProperty("companyName"));
        }

        private ListProperty GetTagsProperty()
        {
            SerializedObject serializedObject = new SerializedObject(AssetDatabase.LoadAllAssetsAtPath("ProjectSettings/TagManager.asset")[0]);
            return new ListProperty(serializedObject.FindProperty("tags"), false, 0);
        }

        private ListProperty GetLayersProperty()
        {
            SerializedObject serializedObject = new SerializedObject(AssetDatabase.LoadAllAssetsAtPath("ProjectSettings/TagManager.asset")[0]);
            return new ListProperty(serializedObject.FindProperty("layers"), true, 8);
        }

        private Physics2DLayerMatrixGuiProperty GetPhysics2DLayerMatrixProperty()
        {
            return new Physics2DLayerMatrixGuiProperty();
        }

        private abstract class MatrixGuiProperty : ICustomProperty
        {
            protected abstract bool GetLayerColision(int layerA, int layerB);
            protected abstract void SetLayerCollision(int layerA, int layerB, bool collides);

            public abstract void Draw();
            public abstract void DrawWithLabel();
            public abstract void DrawWithTitleLabel();

            protected void DrawGrid()
            {
                /*
                 * Nb layers to draw
                 */
                int nbLayers = 0;
                for (int layer = 0; layer < 32; ++layer)
                {
                    if (LayerMask.LayerToName(layer) != "")
                    {
                        ++nbLayers;
                    }
                }
                /*
                 * Max layer label width
                 */
                int maxLayerNameWidth = 100;
                for (int layer = 0; layer < 32; ++layer)
                {
                    Vector2 vector2 = GUI.skin.label.CalcSize(new GUIContent(LayerMask.LayerToName(layer)));
                    if (maxLayerNameWidth < vector2.x)
                    {
                        maxLayerNameWidth = (int) vector2.x;
                    }
                }
                maxLayerNameWidth = maxLayerNameWidth > 150 ? 150 : maxLayerNameWidth;

                /*
                 * Vertical Labels
                 */
                int currentCollumPosition = 0;
                Rect labelsRect = GUILayoutUtility.GetRect(16 * nbLayers + maxLayerNameWidth, maxLayerNameWidth);
                GUIUtility.RotateAroundPivot(90, new Vector2(labelsRect.x, labelsRect.y));
                for (int layer = 31; layer >= 0; layer--)
                {
                    if (LayerMask.LayerToName(layer) != "")
                    {
                        GUI.Label(new Rect(labelsRect.x,
                                           labelsRect.y - maxLayerNameWidth - 45 - 16 * currentCollumPosition,
                                           maxLayerNameWidth,
                                           16f),
                                  LayerMask.LayerToName(layer),
                                  "RightLabel");
                        currentCollumPosition++;
                    }
                }
                GUI.matrix = Matrix4x4.identity;

                /*
                 * Horrizontal Labels and Toggles
                 */
                int currentGridYPosition = 0;
                for (int layer = 0; layer < 32; layer++)
                {
                    if (LayerMask.LayerToName(layer) != "")
                    {
                        Rect lineRectangle = GUILayoutUtility.GetRect(30 + 16 * nbLayers + maxLayerNameWidth, 16f);

                        GUI.Label(new Rect(lineRectangle.x + 30f,
                                           lineRectangle.y,
                                           maxLayerNameWidth,
                                           16f),
                                  LayerMask.LayerToName(layer),
                                  "RightLabel");

                        int currentGridXPosition = 0;
                        for (int otherLayer = 31; otherLayer >= 0; otherLayer--)
                        {
                            if (LayerMask.LayerToName(otherLayer) != "")
                            {
                                if (currentGridXPosition < nbLayers - currentGridYPosition)
                                {
                                    GUIContent content = new GUIContent("", LayerMask.LayerToName(layer) + "/" + LayerMask.LayerToName(otherLayer));
                                    bool layersCollides = GetLayerColision(layer, otherLayer);
                                    bool layersCollidesNew = GUI.Toggle(new Rect(maxLayerNameWidth + 30 + lineRectangle.x + currentGridXPosition * 16,
                                                                                 lineRectangle.y, 16f, 16f),
                                                                        layersCollides,
                                                                        content);
                                    if (layersCollidesNew != layersCollides)
                                    {
                                        SetLayerCollision(layer, otherLayer, layersCollidesNew);
                                    }
                                }
                                currentGridXPosition++;
                            }
                        }
                        currentGridYPosition++;
                    }
                }
            }

            public bool NeedRefresh()
            {
                return false;
            }
        }

        private sealed class Physics2DLayerMatrixGuiProperty : MatrixGuiProperty
        {
            protected override bool GetLayerColision(int layerA, int layerB)
            {
                return !Physics2D.GetIgnoreLayerCollision(layerA, layerB);
            }

            protected override void SetLayerCollision(int layerA, int layerB, bool collides)
            {
                Physics2D.IgnoreLayerCollision(layerA, layerB, !collides);
            }

            public override void Draw()
            {
                DrawGrid();
            }

            public override void DrawWithLabel()
            {
                EditorGUILayout.LabelField("Physics 2D Layer Collison Matrix");
                DrawGrid();
            }

            public override void DrawWithTitleLabel()
            {
                EditorGUILayout.LabelField("Physics 2D Layer Collison Matrix", EditorStyles.boldLabel);
                DrawGrid();
            }
        }
    }
}