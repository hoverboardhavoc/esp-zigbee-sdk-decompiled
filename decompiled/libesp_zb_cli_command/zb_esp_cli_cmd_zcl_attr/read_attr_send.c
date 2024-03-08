/*
 * Last changed at upstream commit 2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * https://github.com/espressif/esp-zigbee-sdk/commit/2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * Upstream date: 2024-03-08 17:10:04 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.0(9d7e9ff2)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zcl_attr.o -> read_attr_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void read_attr_send(undefined4 param_1,uint param_2)

{
  char cVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 *puVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  
  param_2 = param_2 & 0xff;
  puVar4 = (undefined1 *)zb_zcl_get_ctx();
  (&DAT_00011419)[param_2 * 0x3c] = *puVar4;
  iVar5 = zb_schedule_app_alarm(invalidate_row_cb,param_2,0x294,0);
  if (iVar5 == 0) {
    pcVar6 = (char *)zb_buf_reuse_func(param_1);
    iVar5 = param_2 * 0x3c;
    *pcVar6 = (&DAT_00011451)[iVar5] << 3;
    pcVar7 = (char *)zb_zcl_get_ctx();
    cVar1 = *pcVar7;
    *pcVar7 = cVar1 + '\x01';
    pcVar6[1] = cVar1;
    pcVar6[2] = '\0';
    uVar8 = zb_put_next_htole16(pcVar6 + 3,*(undefined2 *)(&DAT_0001142e + iVar5));
    uVar2 = (&DAT_00011428)[iVar5];
    uVar3 = (&DAT_00011429)[iVar5];
    uVar9 = zb_cli_get_endpoint();
    zb_zcl_finish_and_send_packet
              (param_1,uVar8,iVar5 + 0x11420,uVar2,uVar3,uVar9,
               *(undefined2 *)(&DAT_0001142a + iVar5),*(undefined2 *)(&DAT_0001142c + iVar5));
  }
  else {
    uVar8 = esp_log_timestamp();
    esp_log_write(1,&_L0,&_L0,uVar8,&_L0);
    invalidate_row(param_2);
    zb_buf_free_func(param_1);
  }
  return;
}

