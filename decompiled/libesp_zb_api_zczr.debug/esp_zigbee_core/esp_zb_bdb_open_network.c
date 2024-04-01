/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_core.o -> esp_zb_bdb_open_network
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
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC99,uVar3,"ESP_ZIGBEE_CORE");
    uVar3 = 0xffffffff;
  }
  else {
    iVar1 = zb_buf_get_out_func();
    if (iVar1 == 0) {
      uVar3 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC98,uVar3,"ESP_ZIGBEE_CORE","esp_zb_bdb_open_network",
                    0xdea);
      uVar3 = 0x101;
    }
    else {
      puVar2 = (undefined1 *)zb_buf_get_tail_func(4);
      *puVar2 = 0;
      puVar2[1] = 0;
      puVar2[2] = 0;
      puVar2[3] = 0;
      *puVar2 = 0xfc;
      puVar2[1] = 0xff;
      puVar2[2] = param_1;
      puVar2[3] = 1;
      zb_zdo_mgmt_permit_joining_req(iVar1,zb_bdb_open_local_network);
      uVar3 = 0;
    }
  }
  return uVar3;
}

