/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> esp_zb_zdo_device_leave_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_device_leave_req(void *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined2 uVar1;
  undefined2 uVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *__ptr;
  undefined4 uVar5;
  void *__dest;
  uint uVar6;
  
  uVar5 = zb_buf_get_out_func();
  __dest = (void *)zb_buf_get_tail_func(0xb);
  memcpy(__dest,param_1,8);
  uVar1 = *(undefined2 *)((int)param_1 + 10);
  uVar2 = *(undefined2 *)((int)param_1 + 10);
  *(undefined1 *)((int)__dest + 8) = *(undefined1 *)((int)param_1 + 8);
  *(undefined1 *)((int)__dest + 9) = *(undefined1 *)((int)param_1 + 9);
  *(byte *)((int)__dest + 10) =
       *(byte *)((int)__dest + 10) & 0x3f | (byte)uVar1 & 0x80 | (byte)uVar2 & 0x40;
  uVar6 = zdo_mgmt_leave_req(uVar5,device_leave_cb);
  zb_schedule_app_alarm(device_leave_req_timeout,uVar6,0x14a,0);
  pbVar3 = zdo_resp_cb_list_head;
  __ptr = (byte *)malloc(0x10);
  if (__ptr != (byte *)0x0) {
    if (pbVar3 == (byte *)0x0) {
      *__ptr = (byte)uVar6;
      __ptr[1] = 0x34;
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
        pbVar4 = pbVar3;
        if (*pbVar4 == uVar6) {
          free(__ptr);
          return;
        }
        pbVar3 = *(byte **)(pbVar4 + 0xc);
      } while (*(byte **)(pbVar4 + 0xc) != (byte *)0x0);
      *__ptr = (byte)uVar6;
      __ptr[1] = 0x34;
      *(undefined4 *)(__ptr + 4) = param_2;
      *(undefined4 *)(__ptr + 8) = param_3;
      __ptr[0xc] = 0;
      __ptr[0xd] = 0;
      __ptr[0xe] = 0;
      __ptr[0xf] = 0;
      *(byte **)(pbVar4 + 0xc) = __ptr;
    }
  }
  return;
}

