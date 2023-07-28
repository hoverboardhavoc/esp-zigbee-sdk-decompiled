/*
 * Last changed at upstream commit 992d2f5b99d09ff49d4d820bb9dc59b1d40be6d4
 * https://github.com/espressif/esp-zigbee-sdk/commit/992d2f5b99d09ff49d4d820bb9dc59b1d40be6d4
 * Upstream date: 2023-07-28 17:48:58 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.7.2(e1472baa)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> active_ep_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void active_ep_cb(int param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 *puVar3;
  void *__ptr;
  undefined4 uVar4;
  int iVar5;
  
  puVar3 = (undefined1 *)zb_buf_begin_func();
  uVar1 = *puVar3;
  __ptr = calloc(1,1);
  uVar2 = ZDO_INVALID_ENDPOINT;
  if (puVar3[1] == '\0') {
    __ptr = realloc(__ptr,(uint)(byte)puVar3[4]);
    uVar2 = puVar3[4];
    for (iVar5 = 0; iVar5 < (int)(uint)(byte)puVar3[4]; iVar5 = iVar5 + 1) {
      *(undefined1 *)((int)__ptr + iVar5) = puVar3[iVar5 + 5];
    }
    iVar5 = zb_schedule_alarm_cancel(active_ep_req_timeout,0xff,0);
    if (iVar5 != 0) {
      uVar4 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_L0,uVar4,0x10000,"active_ep_cb",0x216);
      return;
    }
  }
  iVar5 = esp_zb_zdo_callback_find(uVar1);
  if (((iVar5 != 0) && (*(char *)(iVar5 + 1) == '\x05')) && (*(code **)(iVar5 + 4) != (code *)0x0))
  {
    (**(code **)(iVar5 + 4))(puVar3[1],uVar2,__ptr,*(undefined4 *)(iVar5 + 8));
  }
  esp_zb_zdo_callback_remove(uVar1);
  if (param_1 != 0) {
    zb_buf_free_func(param_1);
  }
  free(__ptr);
  return;
}

