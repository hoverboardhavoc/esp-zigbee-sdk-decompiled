/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_api.o -> ezb_nwk_get_next_route
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_nwk_get_next_route(ezb_nwk_info_iterator_t *iterator,ezb_nwk_route_info_t *route_info)

{
  ezb_err_t eVar1;
  ezb_shortaddr_t *peVar2;
  
  if (iterator != (ezb_nwk_info_iterator_t *)0x0) {
    eVar1 = 2;
    if (route_info != (ezb_nwk_route_info_t *)0x0) {
      peVar2 = (ezb_shortaddr_t *)nwk_route_table_next(*iterator);
      *iterator = peVar2;
      eVar1 = 5;
      if (peVar2 != (ezb_shortaddr_t *)0x0) {
        eVar1 = 0;
        route_info->dest_addr = *peVar2;
        route_info->next_hop_addr = peVar2[1];
        route_info->expiry = *(uint8_t *)((int)peVar2 + 0xb);
        route_info->flags =
             (anon_struct_1_5_11cf52dc_for_flags)
             ((byte)route_info->flags & 0xc0 | (byte)peVar2[7] & 7 | (byte)peVar2[7] & 8 |
              (byte)peVar2[7] & 0x10 | (byte)peVar2[7] & 0x20);
      }
    }
    return eVar1;
  }
  return 2;
}

