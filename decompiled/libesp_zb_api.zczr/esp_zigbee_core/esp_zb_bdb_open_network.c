/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr -> esp_zigbee_core.o -> esp_zb_bdb_open_network
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_bdb_open_network(undefined1 param_1)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  
  iVar1 = zb_zdo_joined();
  if (iVar1 == 0) {
    uVar3 = esp_log_timestamp();
    esp_log(1,"ESP_ZIGBEE_CORE","E (%lu) %s: Device not in a network, failed to open network\n",
            uVar3,"ESP_ZIGBEE_CORE");
    uVar3 = 0xffffffff;
  }
  else {
    iVar1 = zb_buf_get_out_func();
    uVar3 = 0x101;
    if (iVar1 != 0) {
      puVar2 = (undefined1 *)zb_buf_get_tail_func(4);
      *puVar2 = 0xfc;
      puVar2[1] = 0xff;
      puVar2[3] = 1;
      puVar2[2] = param_1;
      zb_zdo_mgmt_permit_joining_req(iVar1,0x10000);
      uVar3 = 0;
    }
  }
  return uVar3;
}

