/*
 * Last changed at upstream commit b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * https://github.com/espressif/esp-zigbee-sdk/commit/b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * Upstream date: 2024-11-01 15:37:53 +0800
 * Upstream subject: esp-zigbee-lib:(4f5d21fb)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> node_desc_req_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void node_desc_req_timeout(uint param_1)

{
  byte *pbVar1;
  byte *__ptr;
  int iVar2;
  byte *pbVar3;
  
  iVar2 = esp_zb_zdo_callback_find();
  if ((iVar2 != 0) && (*(code **)(iVar2 + 4) != (code *)0x0)) {
    (**(code **)(iVar2 + 4))(0x85,ZDO_INVALID_SHORT_ADDR,0,*(undefined4 *)(iVar2 + 8));
  }
  if (zdo_resp_cb_list_head != (byte *)0x0) {
    pbVar1 = zdo_resp_cb_list_head;
    __ptr = zdo_resp_cb_list_head;
    if (*zdo_resp_cb_list_head == param_1) {
      zdo_resp_cb_list_head = *(byte **)(zdo_resp_cb_list_head + 0xc);
    }
    else {
      do {
        pbVar3 = __ptr;
        __ptr = pbVar1;
        if (__ptr == (byte *)0x0) {
          return;
        }
        pbVar1 = *(byte **)(__ptr + 0xc);
      } while (*__ptr != param_1);
      *(byte **)(pbVar3 + 0xc) = *(byte **)(__ptr + 0xc);
    }
    free(__ptr);
    return;
  }
  return;
}

