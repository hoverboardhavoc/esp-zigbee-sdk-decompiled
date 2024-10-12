/*
 * Last changed at upstream commit d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * https://github.com/espressif/esp-zigbee-sdk/commit/d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * Upstream date: 2024-10-12 11:34:09 +0800
 * Upstream subject: esp-zigbee-lib:(a9edc7b2)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> nwk_addr_req_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_addr_req_timeout(uint param_1)

{
  byte *pbVar1;
  byte *__ptr;
  int iVar2;
  byte *pbVar3;
  
  iVar2 = esp_zb_zdo_callback_find();
  if (iVar2 == 0) {
    return;
  }
  if (*(code **)(iVar2 + 4) != (code *)0x0) {
    (**(code **)(iVar2 + 4))(0x85,ZDO_INVALID_SHORT_ADDR,*(undefined4 *)(iVar2 + 8));
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

