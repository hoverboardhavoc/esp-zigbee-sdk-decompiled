/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_cluster.o -> zcl_cluster_template_remove
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t zcl_cluster_template_remove(uint16_t cluster_id,uint8_t cluster_role)

{
  undefined4 *puVar1;
  ushort *puVar2;
  undefined2 in_register_0000202a;
  int iVar3;
  undefined3 in_register_0000202d;
  
  iVar3 = core_globals_get();
  puVar1 = *(undefined4 **)(iVar3 + 0xd38);
  if (puVar1 != (undefined4 *)0x0) {
    for (; puVar2 = (ushort *)(puVar1 + -5), puVar2 != (ushort *)0xffffffec;
        puVar1 = (undefined4 *)*puVar1) {
      if (((puVar2 != (ushort *)0x0) && ((uint)*puVar2 == CONCAT22(in_register_0000202a,cluster_id))
          ) && ((uint)*(byte *)((int)puVar1 + -0x12) == CONCAT31(in_register_0000202d,cluster_role))
         ) {
        iVar3 = core_globals_get();
        list_remove_node(iVar3 + 0xd38,puVar1);
        break;
      }
    }
    if ((puVar2 != (ushort *)0xffffffec) && (puVar2 != (ushort *)0x0)) {
      mm_free(puVar2);
    }
  }
  return '\0';
}

