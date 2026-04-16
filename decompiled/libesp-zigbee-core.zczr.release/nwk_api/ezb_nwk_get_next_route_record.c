/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_api.o -> ezb_nwk_get_next_route_record
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_nwk_get_next_route_record
                    (ezb_nwk_info_iterator_t *iterator,
                    ezb_nwk_route_record_info_t *route_record_info)

{
  ezb_shortaddr_t eVar1;
  ezb_err_t eVar2;
  ezb_shortaddr_t *peVar3;
  
  if (iterator != (ezb_nwk_info_iterator_t *)0x0) {
    eVar2 = 2;
    if (route_record_info != (ezb_nwk_route_record_info_t *)0x0) {
      peVar3 = (ezb_shortaddr_t *)nwk_route_record_table_next(*iterator);
      *iterator = peVar3;
      eVar2 = 5;
      if (peVar3 != (ezb_shortaddr_t *)0x0) {
        eVar1 = *peVar3;
        route_record_info->expiry = '\0';
        route_record_info->dest_address = eVar1;
        route_record_info->relay_count = (uint8_t)peVar3[1];
        memcpy(route_record_info->path,peVar3 + 2,0x18);
        eVar2 = 0;
      }
    }
    return eVar2;
  }
  return 2;
}

