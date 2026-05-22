/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
  pzVar2 = *(zdo_packet_ctx_entry_t **)(iVar1 + 0xcac);
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

