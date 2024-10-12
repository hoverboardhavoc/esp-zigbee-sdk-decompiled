/*
 * Last changed at upstream commit d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * https://github.com/espressif/esp-zigbee-sdk/commit/d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * Upstream date: 2024-10-12 11:34:09 +0800
 * Upstream subject: esp-zigbee-lib:(a9edc7b2)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> esp_zb_zdo_device_unbind_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_device_unbind_req(void *param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  void *__dest;
  
  uVar2 = zb_buf_get_out_func();
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
  uVar2 = zb_zdo_unbind_req(uVar2,bind_device_cb);
  zb_schedule_app_alarm(bind_device_req_timeout,uVar2,5000000,0);
  esp_zb_zdo_callback_register(uVar2,0x22,param_2,param_3);
  return;
}

