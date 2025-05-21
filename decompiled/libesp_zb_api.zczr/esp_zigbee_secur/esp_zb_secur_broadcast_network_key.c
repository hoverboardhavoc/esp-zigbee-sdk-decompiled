/*
 * Last changed at upstream commit d4fdccd9eea771602c7571d5f751435deed089e9
 * https://github.com/espressif/esp-zigbee-sdk/commit/d4fdccd9eea771602c7571d5f751435deed089e9
 * Upstream date: 2025-05-21 11:16:30 +0000
 * Upstream subject: esp-zigbee-sdk: (5d895722)
 * Source: libesp_zb_api.zczr -> esp_zigbee_secur.o -> esp_zb_secur_broadcast_network_key
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_secur_broadcast_network_key(void *param_1,undefined1 param_2)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  
  if (param_1 != (void *)0x0) {
    iVar1 = zb_is_device_zc();
    if ((iVar1 == 0) &&
       ((iVar1 = zb_is_device_zr(), iVar1 == 0 || (iVar1 = zb_is_network_distributed(), iVar1 == 0))
       )) {
      uVar3 = 0x106;
    }
    else {
      iVar1 = zb_buf_get_out_func();
      uVar3 = 0x101;
      if (iVar1 != 0) {
        puVar2 = (undefined1 *)zb_buf_get_tail_func(0x28);
        *puVar2 = 0xff;
        puVar2[1] = 0xff;
        puVar2[8] = 2;
        puVar2[9] = 1;
        puVar2[0x1b] = 0;
        puVar2[0x1a] = param_2;
        memset(puVar2 + 0x1c,0,8);
        memcpy(puVar2 + 10,param_1,0x10);
        zb_schedule_callback(&zb_apsme_transport_key_request,iVar1);
        uVar3 = 0;
      }
    }
    return uVar3;
  }
  return 0x102;
}

