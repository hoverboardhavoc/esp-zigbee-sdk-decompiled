/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_api.o -> ezb_nwk_get_next_route
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_nwk_get_next_route(ezb_nwk_info_iterator_t *iterator,ezb_nwk_route_info_t *route_info)

{
  ezb_shortaddr_t *peVar1;
  ezb_err_t eVar2;
  
  if (iterator == (ezb_nwk_info_iterator_t *)0x0) {
    eVar2 = 2;
  }
  else if (route_info == (ezb_nwk_route_info_t *)0x0) {
    eVar2 = 2;
  }
  else {
    peVar1 = (ezb_shortaddr_t *)nwk_route_table_next(*iterator);
    *iterator = peVar1;
    if (peVar1 == (ezb_shortaddr_t *)0x0) {
      eVar2 = 5;
    }
    else {
      route_info->dest_addr = *peVar1;
      route_info->next_hop_addr = peVar1[1];
      route_info->expiry = *(uint8_t *)((int)peVar1 + 0xb);
      route_info->flags =
           (anon_struct_1_5_11cf52dc_for_flags)
           ((byte)route_info->flags & 0xf8 | (byte)peVar1[7] & 7);
      route_info->flags =
           (anon_struct_1_5_11cf52dc_for_flags)
           ((byte)((*(uint *)(peVar1 + 6) >> 0x13 & 1) << 3) | (byte)route_info->flags & 0xf7);
      route_info->flags =
           (anon_struct_1_5_11cf52dc_for_flags)
           ((byte)((*(uint *)(peVar1 + 6) >> 0x14 & 1) << 4) | (byte)route_info->flags & 0xef);
      route_info->flags =
           (anon_struct_1_5_11cf52dc_for_flags)
           ((byte)((*(uint *)(peVar1 + 6) >> 0x15 & 1) << 5) | (byte)route_info->flags & 0xdf);
      eVar2 = 0;
    }
  }
  return eVar2;
}

