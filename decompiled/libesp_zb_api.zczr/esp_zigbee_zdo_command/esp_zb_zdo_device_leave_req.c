/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zdo_command.o -> esp_zb_zdo_device_leave_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_device_leave_req(void *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  void *__dest;
  
  uVar3 = zb_buf_get_out_func();
  __dest = (void *)zb_buf_get_tail_func(0xb);
  memcpy(__dest,param_1,8);
  uVar1 = *(undefined2 *)((int)param_1 + 10);
  uVar2 = *(undefined2 *)((int)param_1 + 10);
  *(undefined1 *)((int)__dest + 8) = *(undefined1 *)((int)param_1 + 8);
  *(undefined1 *)((int)__dest + 9) = *(undefined1 *)((int)param_1 + 9);
  *(byte *)((int)__dest + 10) =
       *(byte *)((int)__dest + 10) & 0x3f | (byte)uVar1 & 0x80 | (byte)uVar2 & 0x40;
  uVar3 = zdo_mgmt_leave_req(uVar3,device_leave_cb);
  zb_schedule_app_alarm(device_leave_req_timeout,uVar3,5000000,0);
  esp_zb_zdo_callback_register(uVar3,0x34,param_2,param_3);
  return;
}

