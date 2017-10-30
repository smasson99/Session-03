using Harmony;
using UnityEngine;

/// <summary>
/// Indique que ce GameObject ne doit pas être considéré comme la racine d'une hierachie.
/// </summary>
/// <remarks>
/// <para>
/// Tout GameObject marqué ce de modificateur sera ignoré par la fonction <see cref="GameObjectExtensions.GetRoot"/>. Autrement dit,
/// la recherche de la racine sera arrêté lorsque ce modificateur sera rencontré dans la hierachie. Par exemple :
/// </para>
/// <code>
/// GameObject(DontConsiderAsRoot) == Racine ignorée.
///   - GameObject == Racine retournée.
///     - GameObject
///         - GameObject == Object effectuant la demande.
/// 
/// </code>
/// <para>
/// Cela aura donc un impact sur l'obtention des dépendances via <see cref="RootScope"/> et <see cref="EntityScope"/>.
/// </para>
/// <para>
/// Notez que pour des questions de performance, la recherche de ce modificateur se fait à partir du haut vers le bas, et non
/// pas l'inverse. Si ce modificateur n'est pas rencontré à la racine, il sera tout simplement considéré comme absent, même si,
/// en réalité, il y en a un plus bas dans la hierarchie. Par exemple :
/// </para>
/// <code>
/// GameObject == Racine retournée.
///   - GameObject(DontConsiderAsRoot) == Modificateur ignoré.
///     - GameObject == Racine attendue.
///         - GameObject == Object effectuant la demande.
/// 
/// </code>
/// <para>
/// À la place, vous devez marquer tous les niveaux à ignorer en partant du haut. Par exemple :
/// </para>
/// <code>
/// GameObject(DontConsiderAsRoot) == Racine ignorée.
///   - GameObject(DontConsiderAsRoot) == Racine ignorée.
///     - GameObject == Racine attendue et retournée.
///         - GameObject == Object effectuant la demande.
/// 
/// </code>
/// </remarks>
[AddComponentMenu("Game/Modifiers/DontConsiderAsRoot")]
public sealed class DontConsiderAsRoot : Script
{
}