/*
 * Last changed at upstream commit 438301125bdfa70150622d905094f79315456774
 * https://github.com/espressif/esp-zigbee-sdk/commit/438301125bdfa70150622d905094f79315456774
 * Upstream date: 2024-04-26 19:22:10 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.3.0(a824e1a1)
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
  char *pcVar9;
  int iVar10;
  char *pcVar11;
  char *pcVar12;
  char *pcVar13;
  uint uVar14;
  code *pcVar15;
  undefined1 uStack_28;
  char cStack_27;
  char cStack_26;
  byte bStack_25;
  char *pcStack_24;
  
  pcVar11 = (char *)zb_buf_begin_func();
  pcVar12 = (char *)esp_zb_zdo_callback_find(*pcVar11);
  if (pcVar11[1] == '\0') {
    zb_schedule_alarm_cancel(device_binding_table_req_timeout,0xff,0);
  }
  if (pcVar12 == (char *)0x0) {
    pcVar15 = (code *)0x0;
  }
  else if (*pcVar12 == *pcVar11) {
    if (pcVar12[1] == '3') {
      pcVar15 = *(code **)(pcVar12 + 4);
    }
    else {
      pcVar15 = (code *)0x0;
    }
  }
  else {
    pcVar15 = (code *)0x0;
  }
  if ((pcVar11[1] == '\0') && (pcVar15 != (code *)0x0)) {
    bStack_25 = pcVar11[4];
    uVar14 = (uint)bStack_25;
    pcVar9 = pcVar11 + 5;
    cStack_26 = pcVar11[2];
    cStack_27 = pcVar11[3];
    pcStack_24 = (char *)0x0;
    uStack_28 = 0;
    pcVar11 = (char *)0x0;
    for (iVar10 = 0; iVar10 < (int)uVar14; iVar10 = iVar10 + 1) {
      pcVar13 = (char *)malloc(0x1c);
      *(undefined2 *)(pcVar13 + 10) = *(undefined2 *)(pcVar9 + 9);
      pcVar13[0xc] = pcVar9[0xb];
      pcVar13[8] = pcVar9[8];
      pcVar13[0x16] = pcVar9[0x14];
      cVar1 = pcVar9[1];
      cVar2 = pcVar9[2];
      cVar3 = pcVar9[3];
      cVar4 = pcVar9[4];
      cVar5 = pcVar9[5];
      cVar6 = pcVar9[6];
      cVar7 = pcVar9[7];
      *pcVar13 = *pcVar9;
      pcVar13[1] = cVar1;
      pcVar13[2] = cVar2;
      pcVar13[3] = cVar3;
      pcVar13[4] = cVar4;
      pcVar13[5] = cVar5;
      pcVar13[6] = cVar6;
      pcVar13[7] = cVar7;
      cVar1 = pcVar9[0xd];
      cVar2 = pcVar9[0xe];
      cVar3 = pcVar9[0xf];
      cVar4 = pcVar9[0x10];
      cVar5 = pcVar9[0x11];
      cVar6 = pcVar9[0x12];
      cVar7 = pcVar9[0x13];
      pcVar13[0xe] = pcVar9[0xc];
      pcVar13[0xf] = cVar1;
      pcVar13[0x10] = cVar2;
      pcVar13[0x11] = cVar3;
      pcVar13[0x12] = cVar4;
      pcVar13[0x13] = cVar5;
      pcVar13[0x14] = cVar6;
      pcVar13[0x15] = cVar7;
      pcVar13[0x18] = '\0';
      pcVar13[0x19] = '\0';
      pcVar13[0x1a] = '\0';
      pcVar13[0x1b] = '\0';
      pcVar8 = pcVar13;
      if (pcVar11 != (char *)0x0) {
        *(char **)(pcVar11 + 0x18) = pcVar13;
        pcVar8 = pcStack_24;
      }
      pcStack_24 = pcVar8;
      pcVar9 = pcVar9 + 0x15;
      pcVar11 = pcVar13;
    }
    (*pcVar15)(&uStack_28,*(undefined4 *)(pcVar12 + 8));
    pcVar11 = pcStack_24;
    while (pcVar11 != (char *)0x0) {
      pcVar12 = *(char **)(pcVar11 + 0x18);
      free(pcVar11);
      pcVar11 = pcVar12;
    }
  }
  if (param_1 != 0) {
    zb_buf_free_func(param_1);
  }
  return;
}

