/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_api.o -> ezb_nwk_get_next_neighbor
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_nwk_get_next_neighbor
                    (ezb_nwk_info_iterator_t *iterator,ezb_nwk_neighbor_info_t *nbr_info)

{
  uint8_t uVar1;
  ezb_shortaddr_t eVar2;
  ezb_nwk_info_iterator_t pvVar3;
  ezb_err_t eVar4;
  uint uVar5;
  
  if (iterator == (ezb_nwk_info_iterator_t *)0x0) {
    eVar4 = 2;
  }
  else if (nbr_info == (ezb_nwk_neighbor_info_t *)0x0) {
    eVar4 = 2;
  }
  else {
    pvVar3 = (ezb_nwk_info_iterator_t)nwk_neighbor_table_next(*iterator);
    *iterator = pvVar3;
    if (pvVar3 == (ezb_nwk_info_iterator_t)0x0) {
      eVar4 = 5;
    }
    else {
      nwk_neighbor_get_extaddr(nbr_info);
      eVar2 = nwk_neighbor_get_shortaddr(pvVar3);
      nbr_info->short_addr = eVar2;
      nbr_info->device_type = (byte)*(undefined4 *)((int)pvVar3 + 0xc) & 3;
      nbr_info->depth = (byte)(*(uint *)((int)pvVar3 + 0xc) >> 2) & 0xf;
      nbr_info->rx_on_when_idle = (byte)(*(uint *)((int)pvVar3 + 0xc) >> 10) & 1;
      uVar5 = *(uint *)((int)pvVar3 + 0xc) >> 6 & 0xf;
      uVar1 = (uint8_t)uVar5;
      if (3 < uVar5) {
        uVar1 = '\x03';
      }
      nbr_info->relationship = uVar1;
      uVar1 = nwk_neighbor_get_lqa(pvVar3);
      nbr_info->lqi = uVar1;
      nbr_info->rssi = *(int8_t *)((int)pvVar3 + 5);
      nbr_info->outgoing_cost = (byte)((uint)*(undefined4 *)((int)pvVar3 + 0xc) >> 0x1a) & 7;
      nbr_info->age = (uint8_t)(*(uint *)((int)pvVar3 + 0xc) >> 0x12);
      if ((*(uint *)((int)pvVar3 + 0xc) & 3) == 2) {
        nbr_info->device_timeout = *(uint *)((int)pvVar3 + 0x18) >> 0x14 & 0xf;
        nbr_info->timeout_counter = *(uint *)((int)pvVar3 + 0x18) & 0xfffff;
        eVar4 = 0;
      }
      else {
        nbr_info->device_timeout = 0;
        nbr_info->timeout_counter = 0;
        eVar4 = 0;
      }
    }
  }
  return eVar4;
}

