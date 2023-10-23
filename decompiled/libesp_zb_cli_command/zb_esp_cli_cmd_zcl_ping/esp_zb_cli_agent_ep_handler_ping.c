/*
 * Last changed at upstream commit f1369f27c0afa51d13986c066b316e6812865b18
 * https://github.com/espressif/esp-zigbee-sdk/commit/f1369f27c0afa51d13986c066b316e6812865b18
 * Upstream date: 2023-10-23 12:06:56 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.1(00d5cde0)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zcl_ping.o -> esp_zb_cli_agent_ep_handler_ping
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_cli_agent_ep_handler_ping(undefined4 param_1)

{
  undefined1 uVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uVar4;
  uint *puVar5;
  undefined4 uVar6;
  undefined4 extraout_a1;
  uint uVar7;
  
  pcVar2 = (char *)zb_buf_get_tail_func(0x1b);
  if (*(short *)(pcVar2 + 0xf) == -0x4111) {
    if (*(short *)(pcVar2 + 0x11) == 0x104) {
      if (pcVar2[0x13] == '\x01') {
        puVar5 = (uint *)find_request_by_sn(pcVar2[0x15]);
        if (puVar5 == (uint *)0x0) {
          return 0;
        }
        if (*(char *)((int)puVar5 + 9) == '\x02') {
          uVar7 = *puVar5 >> 8 & 0xffff;
        }
        else {
          uVar7 = zb_address_short_by_ieee((int)puVar5 + 1);
        }
        if (*pcVar2 != '\0') {
          return 0;
        }
        if (*(ushort *)(pcVar2 + 1) != uVar7) {
          return 0;
        }
        uVar4 = get_request_duration(puVar5);
        uVar1 = get_request_row(puVar5);
        iVar3 = zb_schedule_alarm_cancel(invalidate_row_cb,uVar1,0);
        if (iVar3 != 0) {
          uVar6 = esp_log_timestamp();
          esp_log_write(1,&_LC0,&_LC12,uVar6,&_LC0,iVar3);
        }
        if ((code *)puVar5[6] != (code *)0x0) {
          (*(code *)puVar5[6])(0,uVar4,extraout_a1,puVar5);
        }
        if (iVar3 == 0) {
          zb_ping_release_request(puVar5);
        }
      }
      else if (pcVar2[0x13] == '\0') {
        uVar1 = zb_buf_len_func(param_1);
        iVar3 = ping_aquire_reply();
        if (iVar3 == 0) {
          uVar4 = esp_log_timestamp();
          esp_log_write(1,&_LC0,&_LC13,uVar4,&_LC0);
          return 0;
        }
        *(undefined1 *)(iVar3 + 5) = uVar1;
        *(char *)(iVar3 + 4) = pcVar2[0x15];
        uVar4 = esp_log_timestamp();
        esp_log_write(3,&_LC0,&_LC14,uVar4,&_LC0);
        if (*pcVar2 != '\0') {
          uVar4 = esp_log_timestamp();
          esp_log_write(1,&_LC0,&_LC15,uVar4,&_LC0);
          ping_release_reply(iVar3);
          zb_buf_free_func(param_1);
          return 1;
        }
        *(undefined2 *)(iVar3 + 2) = *(undefined2 *)(pcVar2 + 1);
        ping_reply_send(iVar3);
      }
      else {
        uVar4 = esp_log_timestamp();
        esp_log_write(1,&_LC0,&_LC16,uVar4,&_LC0,pcVar2[0x13]);
      }
      zb_buf_free_func(param_1);
      uVar4 = 1;
    }
    else {
      uVar4 = 0;
    }
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}

