using System;
using UnityEngine;
using System.Collections;
using Harmony;
using JetBrains.Annotations;

namespace ProjetSynthese
{
    [AddComponentMenu("Game/Aspect/SpawnOnDestroy")]
    public class SpawnOnDestroy : GameScript
    {
        [NotNull] [SerializeField] private GameObject spawnPoint;
        [NotNull] [SerializeField] private GameObject prefabToSpawn;

        private EntityDestroyer entityDestroyer;

        private void InjectInstanciateOnDestroy([GameObjectScope] EntityDestroyer entityDestroyer)
        {
            this.entityDestroyer = entityDestroyer;
        }

        private void Awake()
        {
            InjectDependencies("InjectInstanciateOnDestroy");
        }

        private void OnEnable()
        {
            entityDestroyer.OnDestroyed += OnDestroyed;
        }

        private void OnDisable()
        {
            entityDestroyer.OnDestroyed -= OnDestroyed;
        }

        private void OnDestroyed()
        {
            Instantiate(prefabToSpawn, spawnPoint.transform.position, spawnPoint.transform.rotation);
        }
    }
}