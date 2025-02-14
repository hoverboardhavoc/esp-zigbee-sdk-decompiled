/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zdo_command.o -> zdo_mgmt_lqi_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_mgmt_lqi_cb(int param_1)

{
  char cVar1;
  void *__dest;
  char *pcVar2;
  char *pcVar3;
  uint __nmemb;
  code *pcVar4;
  undefined4 uVar5;
  int iVar6;
  char cStack_38;
  char cStack_37;
  char cStack_36;
  byte bStack_35;
  void *pvStack_34;
  
  if (param_1 == 0) {
    param_1 = zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_zdo_command.c"
                        ,0x402);
  }
  pcVar2 = (char *)zb_buf_begin_func();
  cVar1 = *pcVar2;
  pcVar3 = (char *)esp_zb_zdo_callback_find(cVar1);
  if (((pcVar3 != (char *)0x0) && (*pcVar3 == cVar1)) && (pcVar3[1] == '1')) {
    zb_schedule_alarm_cancel(zdo_mgmt_lqi_req_timeout,cVar1,0);
    pcVar4 = *(code **)(pcVar3 + 4);
    uVar5 = *(undefined4 *)(pcVar3 + 8);
    if (pcVar4 != (code *)0x0) {
      cStack_38 = pcVar2[1];
      bStack_35 = pcVar2[4];
      __nmemb = (uint)bStack_35;
      cStack_37 = pcVar2[2];
      cStack_36 = pcVar2[3];
      pvStack_34 = calloc(__nmemb,0x16);
      if (pvStack_34 == (void *)0x0) {
        if (__nmemb != 0) {
          cStack_38 = -0x76;
        }
      }
      else {
        pcVar2 = pcVar2 + 5;
        __dest = pvStack_34;
        for (iVar6 = 0; iVar6 < (int)__nmemb; iVar6 = iVar6 + 1) {
          memcpy(__dest,pcVar2,8);
          memcpy((void *)((int)__dest + 8),pcVar2 + 8,8);
          *(undefined2 *)((int)__dest + 0x10) = *(undefined2 *)(pcVar2 + 0x10);
          *(char *)((int)__dest + 0x14) = pcVar2[0x14];
          *(char *)((int)__dest + 0x13) = pcVar2[0x13];
          *(char *)((int)__dest + 0x15) = pcVar2[0x15];
          *(byte *)((int)__dest + 0x12) = pcVar2[0x12] & 0x7f;
          pcVar2 = pcVar2 + 0x16;
          __dest = (void *)((int)__dest + 0x16);
        }
      }
      (*pcVar4)(&cStack_38,uVar5);
      if (pvStack_34 != (void *)0x0) {
        free(pvStack_34);
      }
    }
  }
  zb_buf_free_func(param_1);
  esp_zb_zdo_callback_remove(cVar1);
  return;
}

