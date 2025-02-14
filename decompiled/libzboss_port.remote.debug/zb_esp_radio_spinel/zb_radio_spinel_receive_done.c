/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libzboss_port.remote.debug -> zb_esp_radio_spinel.o -> zb_radio_spinel_receive_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void zb_radio_spinel_receive_done(byte *param_1,undefined1 *param_2)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  void *__dest;
  undefined4 *puVar5;
  uint __n;
  
  if ((param_1 == (byte *)0x0) || (param_2 == (undefined1 *)0x0)) {
    uVar4 = esp_log_timestamp();
    esp_log_write(2,"ZB_ESP_SPINEL",&_L0,uVar4,"ZB_ESP_SPINEL");
  }
  else if ((char)*param_1 < '\0') {
    uVar4 = esp_log_timestamp();
    esp_log_write(2,"ZB_ESP_SPINEL",&_LC3,uVar4,"ZB_ESP_SPINEL");
  }
  else if ((s_mac_raw_frame_handler == (code *)0x0) ||
          (iVar3 = (*s_mac_raw_frame_handler)(), iVar3 == 0)) {
    if ((_esp_radio_spinel_clear_short_entries < 0x14) &&
       ((&g_mac + _esp_radio_spinel_energy_scan != (char *)0x0 &&
        (cVar1 = (&g_mac)[_esp_radio_spinel_energy_scan], cVar1 != '\0')))) {
      __n = *param_1 - 2 & 0xff;
      __dest = (void *)zb_buf_initial_alloc_func(cVar1,__n + 2);
      memcpy(__dest,param_1 + 1,__n);
      uVar2 = esp_zb_rssi_to_lqi((int)(char)param_2[3]);
      *(undefined1 *)(__n + (int)__dest) = uVar2;
      ((undefined1 *)(__n + (int)__dest))[1] = param_2[3];
      puVar5 = (undefined4 *)zb_buf_get_tail_func(cVar1,8);
      uVar4 = *(undefined4 *)(param_2 + 0xc);
      *puVar5 = *(undefined4 *)(param_2 + 8);
      puVar5[1] = uVar4;
      uVar4 = mac_esp_get_received_data_status(param_1,*param_2);
      zb_buf_set_status_func(cVar1,uVar4);
      g_imac = 1;
      _esp_radio_spinel_energy_scan = (_esp_radio_spinel_energy_scan + 1) % 0x14;
      _esp_radio_spinel_clear_short_entries = _esp_radio_spinel_clear_short_entries + 1;
      return;
    }
    uVar4 = esp_log_timestamp();
    esp_log_write(2,"ZB_ESP_SPINEL",&_LC4,uVar4,"ZB_ESP_SPINEL");
  }
  return;
}

