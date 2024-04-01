/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> esp_zb_zdo_device_bind_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_device_bind_req(void *param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *__ptr;
  undefined4 uVar4;
  void *__dest;
  uint uVar5;
  
  uVar4 = zb_buf_get_out_func();
  __dest = (void *)zb_buf_get_tail_func(0x18);
  memcpy(__dest,param_1,8);
  *(undefined1 *)((int)__dest + 8) = *(undefined1 *)((int)param_1 + 8);
  *(undefined2 *)((int)__dest + 10) = *(undefined2 *)((int)param_1 + 10);
  cVar1 = *(char *)((int)param_1 + 0xc);
  *(char *)((int)__dest + 0xc) = cVar1;
  if (cVar1 == '\x01') {
    *(undefined1 *)((int)__dest + 0xd) = *(undefined1 *)((int)param_1 + 0xe);
    *(char *)((int)__dest + 0xe) = (char)((ushort)*(undefined2 *)((int)param_1 + 0xe) >> 8);
  }
  else {
    memcpy((void *)((int)__dest + 0xd),(void *)((int)param_1 + 0xe),8);
  }
  *(undefined1 *)((int)__dest + 0x15) = *(undefined1 *)((int)param_1 + 0x16);
  *(undefined2 *)((int)__dest + 0x16) = *(undefined2 *)((int)param_1 + 0x18);
  uVar5 = zb_zdo_bind_req(uVar4,bind_device_cb);
  zb_schedule_app_alarm(bind_device_req_timeout,uVar5,0x14a,0);
  pbVar2 = zdo_resp_cb_list_head;
  __ptr = (byte *)malloc(0x10);
  if (__ptr != (byte *)0x0) {
    if (pbVar2 == (byte *)0x0) {
      *__ptr = (byte)uVar5;
      __ptr[1] = 0x21;
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
        pbVar3 = pbVar2;
        if (*pbVar3 == uVar5) {
          free(__ptr);
          return;
        }
        pbVar2 = *(byte **)(pbVar3 + 0xc);
      } while (*(byte **)(pbVar3 + 0xc) != (byte *)0x0);
      *__ptr = (byte)uVar5;
      __ptr[1] = 0x21;
      *(undefined4 *)(__ptr + 4) = param_2;
      *(undefined4 *)(__ptr + 8) = param_3;
      __ptr[0xc] = 0;
      __ptr[0xd] = 0;
      __ptr[0xe] = 0;
      __ptr[0xf] = 0;
      *(byte **)(pbVar3 + 0xc) = __ptr;
    }
  }
  return;
}

