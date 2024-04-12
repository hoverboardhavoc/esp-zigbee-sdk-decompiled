/*
 * Last changed at upstream commit e28462af08968da8dbda59a317df742f0109ee5f
 * https://github.com/espressif/esp-zigbee-sdk/commit/e28462af08968da8dbda59a317df742f0109ee5f
 * Upstream date: 2024-04-12 14:44:19 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.3(042315bf)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> esp_zb_zdo_binding_table_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_binding_table_req(undefined1 *param_1,undefined4 param_2,undefined4 param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *__ptr;
  undefined4 uVar3;
  undefined1 *puVar4;
  uint uVar5;
  
  uVar3 = zb_buf_get_out_func();
  puVar4 = (undefined1 *)zb_buf_get_tail_func(4);
  *(undefined2 *)(puVar4 + 2) = *(undefined2 *)(param_1 + 2);
  *puVar4 = *param_1;
  uVar5 = zb_zdo_mgmt_bind_req(uVar3,zdo_binding_table_resp);
  zb_schedule_app_alarm(device_binding_table_req_timeout,uVar5,5000000,0);
  pbVar1 = zdo_resp_cb_list_head;
  __ptr = (byte *)malloc(0x10);
  if (__ptr != (byte *)0x0) {
    if (pbVar1 == (byte *)0x0) {
      *__ptr = (byte)uVar5;
      __ptr[1] = 0x33;
      *(undefined4 *)(__ptr + 4) = param_2;
      *(undefined4 *)(__ptr + 8) = param_3;
      __ptr[0xc] = 0;
      __ptr[0xd] = 0;
      __ptr[0xe] = 0;
      __ptr[0xf] = 0;
      zdo_resp_cb_list_head = __ptr;
    }
    else {
      do {
        pbVar2 = pbVar1;
        if (*pbVar2 == uVar5) {
          free(__ptr);
          return;
        }
        pbVar1 = *(byte **)(pbVar2 + 0xc);
      } while (*(byte **)(pbVar2 + 0xc) != (byte *)0x0);
      *__ptr = (byte)uVar5;
      __ptr[1] = 0x33;
      *(undefined4 *)(__ptr + 4) = param_2;
      *(undefined4 *)(__ptr + 8) = param_3;
      __ptr[0xc] = 0;
      __ptr[0xd] = 0;
      __ptr[0xe] = 0;
      __ptr[0xf] = 0;
      *(byte **)(pbVar2 + 0xc) = __ptr;
    }
  }
  return;
}

