/*
 * Last changed at upstream commit 2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * https://github.com/espressif/esp-zigbee-sdk/commit/2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * Upstream date: 2024-03-08 17:10:04 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.0(9d7e9ff2)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zcl_general_cmd.o -> general_cmd_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void general_cmd_send(undefined4 param_1,uint param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  
  puVar3 = (undefined1 *)zb_zcl_get_ctx();
  iVar5 = param_2 * 0x2e;
  (&DAT_00010d79)[iVar5] = *puVar3;
  puVar3 = (undefined1 *)
           zb_zcl_start_command_header
                     (param_1,((byte)(&DAT_00010da4)[iVar5] & 0xf) << 4 | 1,0,(&DAT_00010da2)[iVar5]
                      ,0);
  for (uVar6 = 0; iVar5 = param_2 * 0x2e, uVar6 < (byte)(&DAT_00010da1)[iVar5];
      uVar6 = uVar6 + 1 & 0xff) {
    *puVar3 = (&DAT_00010d88)[param_2 * 0x2e + uVar6];
    puVar3 = puVar3 + 1;
  }
  uVar1 = (&DAT_00010d7a)[iVar5];
  uVar2 = (&DAT_00010d83)[iVar5];
  uVar4 = zb_cli_get_endpoint();
  zb_zcl_finish_and_send_packet
            (param_1,puVar3,&DAT_00010d7b + iVar5,uVar1,uVar2,uVar4,
             *(undefined2 *)(&DAT_00010d84 + iVar5),*(undefined2 *)(&DAT_00010d86 + iVar5));
  if ((&DAT_00010da4)[iVar5] == '\0') {
    iVar5 = zb_schedule_app_alarm(invalidate_row_cb,param_2 & 0xff,0x294,0);
    if (iVar5 != 0) {
      uVar4 = esp_log_timestamp();
      esp_log_write(1,&_L0,&_LC1,uVar4,&_L0);
      invalidate_row(param_2 & 0xff);
    }
  }
  else {
    uVar4 = esp_log_timestamp();
    esp_log_write(3,&_L0,&_LC2,uVar4,&_L0);
    invalidate_row(param_2 & 0xff);
  }
  return;
}

