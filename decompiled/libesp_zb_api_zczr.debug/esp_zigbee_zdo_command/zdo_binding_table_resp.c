/*
 * Last changed at upstream commit e28462af08968da8dbda59a317df742f0109ee5f
 * https://github.com/espressif/esp-zigbee-sdk/commit/e28462af08968da8dbda59a317df742f0109ee5f
 * Upstream date: 2024-04-12 14:44:19 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.3(042315bf)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zdo_command.o -> zdo_binding_table_resp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_binding_table_resp(int param_1)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  char *pcVar8;
  int iVar9;
  char *pcVar10;
  char *pcVar11;
  char *pcVar12;
  uint uVar13;
  code *pcVar14;
  undefined1 uStack_28;
  char cStack_27;
  char cStack_26;
  byte bStack_25;
  char *pcStack_24;
  
  pcVar10 = (char *)zb_buf_begin_func();
  pcVar11 = (char *)esp_zb_zdo_callback_find(*pcVar10);
  if (pcVar10[1] == '\0') {
    zb_schedule_alarm_cancel(device_binding_table_req_timeout,0xff,0);
  }
  if (pcVar11 == (char *)0x0) {
    pcVar14 = (code *)0x0;
  }
  else if (*pcVar11 == *pcVar10) {
    if (pcVar11[1] == '3') {
      pcVar14 = *(code **)(pcVar11 + 4);
    }
    else {
      pcVar14 = (code *)0x0;
    }
  }
  else {
    pcVar14 = (code *)0x0;
  }
  if ((pcVar10[1] == '\0') && (pcVar14 != (code *)0x0)) {
    bStack_25 = pcVar10[4];
    uVar13 = (uint)bStack_25;
    pcVar11 = pcVar10 + 5;
    cStack_26 = pcVar10[2];
    cStack_27 = pcVar10[3];
    pcStack_24 = (char *)0x0;
    uStack_28 = 0;
    pcVar10 = (char *)0x0;
    for (iVar9 = 0; iVar9 < (int)uVar13; iVar9 = iVar9 + 1) {
      pcVar12 = (char *)malloc(0x1c);
      *(undefined2 *)(pcVar12 + 10) = *(undefined2 *)(pcVar11 + 9);
      pcVar12[0xc] = pcVar11[0xb];
      pcVar12[8] = pcVar11[8];
      pcVar12[0x16] = pcVar11[0x14];
      cVar1 = pcVar11[1];
      cVar2 = pcVar11[2];
      cVar3 = pcVar11[3];
      cVar4 = pcVar11[4];
      cVar5 = pcVar11[5];
      cVar6 = pcVar11[6];
      cVar7 = pcVar11[7];
      *pcVar12 = *pcVar11;
      pcVar12[1] = cVar1;
      pcVar12[2] = cVar2;
      pcVar12[3] = cVar3;
      pcVar12[4] = cVar4;
      pcVar12[5] = cVar5;
      pcVar12[6] = cVar6;
      pcVar12[7] = cVar7;
      cVar1 = pcVar11[0xd];
      cVar2 = pcVar11[0xe];
      cVar3 = pcVar11[0xf];
      cVar4 = pcVar11[0x10];
      cVar5 = pcVar11[0x11];
      cVar6 = pcVar11[0x12];
      cVar7 = pcVar11[0x13];
      pcVar12[0xe] = pcVar11[0xc];
      pcVar12[0xf] = cVar1;
      pcVar12[0x10] = cVar2;
      pcVar12[0x11] = cVar3;
      pcVar12[0x12] = cVar4;
      pcVar12[0x13] = cVar5;
      pcVar12[0x14] = cVar6;
      pcVar12[0x15] = cVar7;
      pcVar12[0x18] = '\0';
      pcVar12[0x19] = '\0';
      pcVar12[0x1a] = '\0';
      pcVar12[0x1b] = '\0';
      pcVar8 = pcVar12;
      if (pcVar10 != (char *)0x0) {
        *(char **)(pcVar10 + 0x18) = pcVar12;
        pcVar8 = pcStack_24;
      }
      pcStack_24 = pcVar8;
      pcVar11 = pcVar11 + 0x15;
      pcVar10 = pcVar12;
    }
    (*pcVar14)(&uStack_28,0);
    pcVar10 = pcStack_24;
    while (pcVar10 != (char *)0x0) {
      pcVar11 = *(char **)(pcVar10 + 0x18);
      free(pcVar10);
      pcVar10 = pcVar11;
    }
  }
  if (param_1 != 0) {
    zb_buf_free_func(param_1);
  }
  return;
}

