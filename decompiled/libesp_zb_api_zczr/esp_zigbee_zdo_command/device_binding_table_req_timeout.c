/*
 * Last changed at upstream commit eec5098a388a0960da2662a0145e34c21f0838a0
 * https://github.com/espressif/esp-zigbee-sdk/commit/eec5098a388a0960da2662a0145e34c21f0838a0
 * Upstream date: 2024-08-27 08:46:30 +0000
 * Upstream subject: esp-zigbee-lib:(6bd34178)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> device_binding_table_req_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void device_binding_table_req_timeout(uint param_1)

{
  byte *pbVar1;
  byte *__ptr;
  int iVar2;
  byte *pbVar3;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  iVar2 = esp_zb_zdo_callback_find();
  if ((iVar2 != 0) && (*(code **)(iVar2 + 4) != (code *)0x0)) {
    uStack_14 = 0;
    uStack_18 = 0x85;
    (**(code **)(iVar2 + 4))(&uStack_18,*(undefined4 *)(iVar2 + 8));
  }
  pbVar1 = zdo_resp_cb_list_head;
  __ptr = zdo_resp_cb_list_head;
  if ((zdo_resp_cb_list_head == (byte *)0x0) || (*zdo_resp_cb_list_head != param_1)) {
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
  else {
    zdo_resp_cb_list_head = *(byte **)(zdo_resp_cb_list_head + 0xc);
  }
  free(__ptr);
  return;
}

