/*
 * Last changed at upstream commit 438301125bdfa70150622d905094f79315456774
 * https://github.com/espressif/esp-zigbee-sdk/commit/438301125bdfa70150622d905094f79315456774
 * Upstream date: 2024-04-26 19:22:10 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.3.0(a824e1a1)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> zdo_binding_table_resp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_binding_table_resp(int param_1)

{
  void *pvVar1;
  char *__src;
  char *pcVar2;
  char *pcVar3;
  void *pvVar4;
  void *__dest;
  int iVar5;
  code *pcVar6;
  uint uVar7;
  undefined1 uStack_38;
  char cStack_37;
  char cStack_36;
  byte bStack_35;
  void *pvStack_34;
  
  pcVar2 = (char *)zb_buf_begin_func();
  pcVar3 = (char *)esp_zb_zdo_callback_find(*pcVar2);
  if (pcVar2[1] == '\0') {
    zb_schedule_alarm_cancel(device_binding_table_req_timeout,0xff,0);
  }
  if ((((pcVar3 != (char *)0x0) && (*pcVar3 == *pcVar2)) && (pcVar3[1] == '3')) &&
     ((pcVar2[1] == '\0' && (pcVar6 = *(code **)(pcVar3 + 4), pcVar6 != (code *)0x0)))) {
    cStack_36 = pcVar2[2];
    bStack_35 = pcVar2[4];
    uVar7 = (uint)bStack_35;
    __src = pcVar2 + 5;
    cStack_37 = pcVar2[3];
    uStack_38 = 0;
    pvStack_34 = (void *)0x0;
    pvVar4 = (void *)0x0;
    for (iVar5 = 0; iVar5 < (int)uVar7; iVar5 = iVar5 + 1) {
      __dest = malloc(0x1c);
      *(undefined2 *)((int)__dest + 10) = *(undefined2 *)(__src + 9);
      *(char *)((int)__dest + 0xc) = __src[0xb];
      *(char *)((int)__dest + 8) = __src[8];
      *(char *)((int)__dest + 0x16) = __src[0x14];
      memcpy(__dest,__src,8);
      memcpy((void *)((int)__dest + 0xe),__src + 0xc,8);
      *(undefined4 *)((int)__dest + 0x18) = 0;
      pvVar1 = __dest;
      if (pvVar4 != (void *)0x0) {
        *(void **)((int)pvVar4 + 0x18) = __dest;
        pvVar1 = pvStack_34;
      }
      pvStack_34 = pvVar1;
      __src = __src + 0x15;
      pvVar4 = __dest;
    }
    (*pcVar6)(&uStack_38,*(undefined4 *)(pcVar3 + 8));
    pvVar4 = pvStack_34;
    while (pvVar4 != (void *)0x0) {
      pvVar1 = *(void **)((int)pvVar4 + 0x18);
      free(pvVar4);
      pvVar4 = pvVar1;
    }
  }
  if (param_1 != 0) {
    zb_buf_free_func(param_1);
  }
  return;
}

