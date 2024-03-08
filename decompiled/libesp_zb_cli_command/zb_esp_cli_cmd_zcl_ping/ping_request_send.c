/*
 * Last changed at upstream commit 2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * https://github.com/espressif/esp-zigbee-sdk/commit/2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * Upstream date: 2024-03-08 17:10:04 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.0(9d7e9ff2)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zcl_ping.o -> ping_request_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ping_request_send(int param_1)

{
  ushort uVar1;
  char cVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined4 uVar7;
  undefined4 extraout_a1;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  uVar4 = zb_cli_get_endpoint();
  if (*(ushort *)(param_1 + 0xc) < 0x50) {
    iVar5 = zb_buf_get_out_func();
    if (iVar5 == 0) {
      if (*(code **)(param_1 + 0x18) != (code *)0x0) {
        (**(code **)(param_1 + 0x18))(2,0,0,param_1);
      }
    }
    else {
      puVar6 = (undefined1 *)zb_buf_reuse_func();
      *puVar6 = 0x11;
      cVar2 = m_ping_seq_num;
      puVar6[1] = m_ping_seq_num;
      puVar6[2] = 0;
      memset(puVar6 + 3,0xab,(uint)*(ushort *)(param_1 + 0xc));
      uVar1 = *(ushort *)(param_1 + 0xc);
      *(char *)(param_1 + 10) = cVar2;
      m_ping_seq_num = cVar2 + '\x01';
      uVar7 = abs_time_now();
      *(undefined4 *)(param_1 + 0x10) = uVar7;
      *(undefined4 *)(param_1 + 0x14) = extraout_a1;
      zb_zcl_finish_and_send_packet_no_ack
                (iVar5,puVar6 + 3 + uVar1,param_1 + 1,*(undefined1 *)(param_1 + 9),uVar4,uVar4,0x104
                 ,0xbeef);
      uVar3 = get_request_row(param_1);
      uVar9 = (uint)*(ushort *)(param_1 + 0xe) * 1000;
      uVar8 = uVar9 + 0x3bff;
      uVar10 = (uint)(uVar8 < uVar9);
      uVar9 = uVar8 + uVar10;
      uVar9 = uVar8 - (uVar9 + (uVar9 < uVar8)) % 0xf;
      uVar8 = (uVar10 - (uVar8 < uVar9)) * -0x11111111 + uVar9 * -0x11111112 +
              (int)((ulonglong)uVar9 * 0xeeeeeeef >> 0x20);
      iVar5 = zb_schedule_app_alarm
                        (invalidate_row_cb,uVar3,uVar8 * 0x400000 | uVar9 * -0x11111111 >> 10,
                         uVar8 >> 10);
      if (iVar5 != 0) {
        uVar4 = esp_log_timestamp();
        esp_log_write(3,&_LC0,&_L0,uVar4,&_LC0,iVar5);
      }
    }
  }
  else if (*(code **)(param_1 + 0x18) != (code *)0x0) {
    (**(code **)(param_1 + 0x18))(2,0,0,param_1);
  }
  return;
}

