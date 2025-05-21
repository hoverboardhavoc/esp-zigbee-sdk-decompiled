/*
 * Last changed at upstream commit d4fdccd9eea771602c7571d5f751435deed089e9
 * https://github.com/espressif/esp-zigbee-sdk/commit/d4fdccd9eea771602c7571d5f751435deed089e9
 * Upstream date: 2025-05-21 11:16:30 +0000
 * Upstream subject: esp-zigbee-sdk: (5d895722)
 * Source: libesp_zb_api.zczr -> esp_zigbee_secur.o -> esp_zb_secur_broadcast_network_key_switch
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_secur_broadcast_network_key_switch(undefined1 param_1)

{
  int iVar1;
  void *__s;
  undefined4 uVar2;
  
  iVar1 = zb_is_device_zc();
  if ((iVar1 == 0) &&
     ((iVar1 = zb_is_device_zr(), iVar1 == 0 || (iVar1 = zb_is_network_distributed(), iVar1 == 0))))
  {
    uVar2 = 0x106;
  }
  else {
    iVar1 = zb_buf_get_out_func();
    uVar2 = 0x101;
    if (iVar1 != 0) {
      __s = (void *)zb_buf_get_tail_func(9);
      memset(__s,0xff,8);
      *(undefined1 *)((int)__s + 8) = param_1;
      zb_schedule_callback(&zb_apsme_switch_key_request,iVar1);
      uVar2 = 0;
    }
  }
  return uVar2;
}

