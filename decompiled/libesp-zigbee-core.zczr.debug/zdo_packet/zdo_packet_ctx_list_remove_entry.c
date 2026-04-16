/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
  puVar1 = *(undefined4 **)(iVar3 + 0xd10);
  if (puVar1 != (undefined4 *)0x0) {
    for (; pzVar2 = (zdo_packet_ctx_entry_t *)(puVar1 + -9),
        pzVar2 != (zdo_packet_ctx_entry_t *)0xffffffdc; puVar1 = (undefined4 *)*puVar1) {
      if ((puVar1 != (undefined4 *)0x24) && (pzVar2 == ent)) {
        iVar3 = core_globals_get();
        list_remove_node(iVar3 + 0xd10,puVar1);
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

