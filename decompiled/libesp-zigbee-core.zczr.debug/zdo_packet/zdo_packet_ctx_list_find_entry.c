/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_packet.o -> zdo_packet_ctx_list_find_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdo_packet_ctx_entry_t * zdo_packet_ctx_list_find_entry(uint8_t tsn)

{
  undefined3 in_register_00002029;
  int iVar1;
  zdo_packet_ctx_entry_t *pzVar2;
  zdo_packet_ctx_entry_t *pzVar3;
  
  iVar1 = core_globals_get();
  pzVar2 = *(zdo_packet_ctx_entry_t **)(iVar1 + 0xd10);
  pzVar3 = pzVar2;
  if (pzVar2 != (zdo_packet_ctx_entry_t *)0x0) {
    while ((pzVar2 = (zdo_packet_ctx_entry_t *)&pzVar3[-1].timer,
           pzVar2 != (zdo_packet_ctx_entry_t *)0xffffffdc &&
           ((pzVar2 == (zdo_packet_ctx_entry_t *)0x0 ||
            ((uint)*(byte *)&((milli_timer_t *)pzVar2)->next != CONCAT31(in_register_00002029,tsn)))
           ))) {
      pzVar3 = *(zdo_packet_ctx_entry_t **)pzVar3;
    }
    if (pzVar2 == (zdo_packet_ctx_entry_t *)0xffffffdc) {
      pzVar2 = (zdo_packet_ctx_entry_t *)0x0;
    }
  }
  return pzVar2;
}

