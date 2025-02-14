/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_core.o -> esp_zb_bdb_open_network
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
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC24,uVar3,"ESP_ZIGBEE_CORE");
    uVar3 = 0xffffffff;
  }
  else {
    iVar1 = zb_buf_get_out_func();
    if (iVar1 == 0) {
      uVar3 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC23,uVar3,"ESP_ZIGBEE_CORE","esp_zb_bdb_open_network",
                    0x4f8);
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

