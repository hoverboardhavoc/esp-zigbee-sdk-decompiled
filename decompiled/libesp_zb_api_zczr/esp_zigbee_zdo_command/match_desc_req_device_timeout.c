/*
 * Last changed at upstream commit 3ee1c52790580ff8c3ec33b61f57334e0f637dc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/3ee1c52790580ff8c3ec33b61f57334e0f637dc8
 * Upstream date: 2023-05-26 18:12:14 +0800
 * Upstream subject: esp-zboss: Provide zboss APIs to fix github issues(70cea8e)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> match_desc_req_device_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void match_desc_req_device_timeout(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = esp_log_timestamp();
  esp_log_write(3,0x10000,&_L0,uVar1,0x10000);
  iVar2 = esp_zb_zdo_callback_find(param_1);
  if ((iVar2 != 0) && (*(code **)(iVar2 + 4) != (code *)0x0)) {
    (**(code **)(iVar2 + 4))
              (0x85,ZDO_INVALID_SHORT_ADDR,ZDO_INVALID_ENDPOINT,*(undefined4 *)(iVar2 + 8));
  }
  esp_zb_zdo_callback_remove(param_1);
  return;
}

