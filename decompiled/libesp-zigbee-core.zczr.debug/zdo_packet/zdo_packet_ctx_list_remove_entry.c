/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_packet.o -> zdo_packet_ctx_list_remove_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zdo_packet_ctx_list_remove_entry(zdo_packet_ctx_entry_t *ent)

{
  undefined4 *puVar1;
  zdo_packet_ctx_entry_t *pzVar2;
  int iVar3;
  
  iVar3 = core_globals_get();
  puVar1 = *(undefined4 **)(iVar3 + 0xcac);
  if (puVar1 != (undefined4 *)0x0) {
    for (; pzVar2 = (zdo_packet_ctx_entry_t *)(puVar1 + -9),
        pzVar2 != (zdo_packet_ctx_entry_t *)0xffffffdc; puVar1 = (undefined4 *)*puVar1) {
      if ((puVar1 != (undefined4 *)0x24) && (pzVar2 == ent)) {
        iVar3 = core_globals_get();
        list_remove_node(iVar3 + 0xcac,puVar1);
        break;
      }
    }
    if (((pzVar2 != (zdo_packet_ctx_entry_t *)0xffffffdc) && (puVar1 != (undefined4 *)0x24)) &&
       (*(char *)(puVar1 + -3) != '\0')) {
      nwk_pim_stop_fast_poll();
    }
  }
  return;
}

