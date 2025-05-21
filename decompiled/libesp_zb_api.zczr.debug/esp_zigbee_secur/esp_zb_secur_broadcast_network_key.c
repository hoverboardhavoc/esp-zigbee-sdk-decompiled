/*
 * Last changed at upstream commit d4fdccd9eea771602c7571d5f751435deed089e9
 * https://github.com/espressif/esp-zigbee-sdk/commit/d4fdccd9eea771602c7571d5f751435deed089e9
 * Upstream date: 2025-05-21 11:16:30 +0000
 * Upstream subject: esp-zigbee-sdk: (5d895722)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_secur.o -> esp_zb_secur_broadcast_network_key
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
  undefined4 uVar4;
  
  if (param_1 == (void *)0x0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_SECUR",&_LC2,uVar3,"ESP_ZIGBEE_SECUR",
                  "esp_zb_secur_broadcast_network_key",0x113);
    uVar3 = 0x102;
  }
  else {
    iVar1 = zb_is_device_zc();
    if ((iVar1 == 0) &&
       ((iVar1 = zb_is_device_zr(), iVar1 == 0 || (iVar1 = zb_is_network_distributed(), iVar1 == 0))
       )) {
      uVar3 = esp_log_timestamp();
      uVar4 = zb_get_network_role();
      esp_log_write(1,"ESP_ZIGBEE_SECUR",&_LC3,uVar3,"ESP_ZIGBEE_SECUR",
                    "esp_zb_secur_broadcast_network_key",0x114,uVar4);
      uVar3 = 0x106;
    }
    else {
      iVar1 = zb_buf_get_out_func();
      if (iVar1 == 0) {
        uVar3 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_SECUR",&_LC4,uVar3,"ESP_ZIGBEE_SECUR",
                      "esp_zb_secur_broadcast_network_key",0x116);
        uVar3 = 0x101;
      }
      else {
        puVar2 = (undefined1 *)zb_buf_get_tail_func(0x28);
        *puVar2 = 0xff;
        puVar2[1] = 0xff;
        puVar2[8] = 2;
        puVar2[9] = 1;
        puVar2[0x1b] = 0;
        puVar2[0x1a] = param_2;
        puVar2[0x1c] = 0;
        puVar2[0x1d] = 0;
        puVar2[0x1e] = 0;
        puVar2[0x1f] = 0;
        puVar2[0x20] = 0;
        puVar2[0x21] = 0;
        puVar2[0x22] = 0;
        puVar2[0x23] = 0;
        memcpy(puVar2 + 10,param_1,0x10);
        zb_schedule_callback(&zb_apsme_transport_key_request,iVar1);
        uVar3 = 0;
      }
    }
  }
  return uVar3;
}

