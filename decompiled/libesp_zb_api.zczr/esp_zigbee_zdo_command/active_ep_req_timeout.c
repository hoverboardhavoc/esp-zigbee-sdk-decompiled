/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zdo_command.o -> active_ep_req_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void active_ep_req_timeout(uint param_1)

{
  byte *pbVar1;
  byte *__ptr;
  int iVar2;
  byte *pbVar3;
  
  iVar2 = esp_zb_zdo_callback_find();
  if ((iVar2 != 0) && (*(code **)(iVar2 + 4) != (code *)0x0)) {
    (**(code **)(iVar2 + 4))(0x85,ZDO_INVALID_ENDPOINT,0,*(undefined4 *)(iVar2 + 8));
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

