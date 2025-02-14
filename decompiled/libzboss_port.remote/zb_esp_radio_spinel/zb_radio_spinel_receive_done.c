/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libzboss_port.remote -> zb_esp_radio_spinel.o -> zb_radio_spinel_receive_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void zb_radio_spinel_receive_done(byte *param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  undefined1 uVar3;
  void *__dest;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  uint __n;
  undefined1 auStack_38 [20];
  byte bStack_24;
  
  if (param_1 == (byte *)0x0) {
    return;
  }
  if ((((param_2 != (char *)0x0) && (-1 < (char)*param_1)) &&
      ((s_mac_raw_frame_handler == (code *)0x0 || (iVar5 = (*s_mac_raw_frame_handler)(), iVar5 == 0)
       ))) && ((_esp_radio_spinel_add_extended_entry < 0x14 &&
               (cVar1 = (&g_mac)[_esp_radio_spinel_clear_extended_entries], cVar1 != '\0')))) {
    __n = *param_1 - 2 & 0xff;
    __dest = (void *)zb_buf_initial_alloc_func(cVar1,__n + 2);
    memcpy(__dest,param_1 + 1,__n);
    uVar3 = esp_zb_rssi_to_lqi((int)param_2[3]);
    *(undefined1 *)(__n + (int)__dest) = uVar3;
    ((undefined1 *)(__n + (int)__dest))[1] = param_2[3];
    puVar4 = (undefined4 *)zb_buf_get_tail_func(cVar1,8);
    uVar6 = *(undefined4 *)(param_2 + 0xc);
    *puVar4 = *(undefined4 *)(param_2 + 8);
    puVar4[1] = uVar6;
    cVar2 = *param_2;
    iVar5 = zb_parse_mhr_ptr(auStack_38,param_1);
    uVar6 = 0;
    if (((bStack_24 & 7) == 3) && ((param_1[iVar5] == 4 && (cVar2 == '\0')))) {
      uVar6 = 0xeb;
    }
    zb_buf_set_status_func(cVar1,uVar6);
    _esp_radio_spinel_add_extended_entry = _esp_radio_spinel_add_extended_entry + 1;
    _esp_radio_spinel_clear_extended_entries = (_esp_radio_spinel_clear_extended_entries + 1) % 0x14
    ;
    g_imac = 1;
  }
  return;
}

