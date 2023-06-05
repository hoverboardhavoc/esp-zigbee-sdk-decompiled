/*
 * Last changed at upstream commit 503c5e49627f84174ce142bf784c3f01532fb5c9
 * https://github.com/espressif/esp-zigbee-sdk/commit/503c5e49627f84174ce142bf784c3f01532fb5c9
 * Upstream date: 2023-06-05 10:37:46 +0800
 * Upstream subject: esp-zigbee-sdk: optimize the zigbee cluster implementation(0f0acd4)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> active_ep_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void active_ep_cb(int param_1)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  void *__ptr;
  int iVar3;
  undefined1 uVar4;
  
  puVar2 = (undefined1 *)zb_buf_begin_func();
  uVar1 = *puVar2;
  __ptr = calloc(1,1);
  uVar4 = ZDO_INVALID_ENDPOINT;
  if (puVar2[1] == '\0') {
    __ptr = realloc(__ptr,(uint)(byte)puVar2[4]);
    uVar4 = puVar2[4];
    for (iVar3 = 0; iVar3 < (int)(uint)(byte)puVar2[4]; iVar3 = iVar3 + 1) {
      *(undefined1 *)((int)__ptr + iVar3) = puVar2[iVar3 + 5];
    }
    iVar3 = zb_schedule_alarm_cancel(active_ep_req_timeout,0xff,0);
    if (iVar3 == 0) goto _L0;
    iVar3 = _esp_error_check_failed
                      ("/home/xieqinan/ESP/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_zdo_command.c"
                       ,0x1e2,"active_ep_cb",
                       "ZB_SCHEDULE_APP_ALARM_CANCEL(active_ep_req_timeout, ZB_ALARM_ANY_PARAM)");
  }
  else {
_L0:
    iVar3 = esp_zb_zdo_callback_find(uVar1);
    if ((iVar3 == 0) || (*(char *)(iVar3 + 1) != '\x05')) goto _L0;
  }
  if (*(code **)(iVar3 + 4) != (code *)0x0) {
    (**(code **)(iVar3 + 4))(puVar2[1],uVar4,__ptr,*(undefined4 *)(iVar3 + 8));
  }
_L0:
  esp_zb_zdo_callback_remove(uVar1);
  if (param_1 != 0) {
    zb_buf_free_func(param_1);
  }
  free(__ptr);
  return;
}

