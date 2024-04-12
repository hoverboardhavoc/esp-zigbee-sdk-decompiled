/*
 * Last changed at upstream commit e28462af08968da8dbda59a317df742f0109ee5f
 * https://github.com/espressif/esp-zigbee-sdk/commit/e28462af08968da8dbda59a317df742f0109ee5f
 * Upstream date: 2024-04-12 14:44:19 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.3(042315bf)
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
      iVar5 = zb_schedule_app_alarm
                        (invalidate_row_cb,uVar3,(uint)*(ushort *)(param_1 + 0xe) * 1000,0);
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

