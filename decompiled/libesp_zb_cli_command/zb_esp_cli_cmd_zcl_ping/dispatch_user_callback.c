/*
 * Last changed at upstream commit 2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * https://github.com/espressif/esp-zigbee-sdk/commit/2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * Upstream date: 2024-03-08 17:10:04 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.0(9d7e9ff2)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zcl_ping.o -> dispatch_user_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void dispatch_user_callback(int param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (param_1 == 0) {
    return;
  }
  piVar1 = (int *)zb_buf_get_tail_func(0x10);
  if (*(char *)((int)piVar1 + 5) == '\0') {
    uVar2 = (uint)*(ushort *)((int)piVar1 + 6);
  }
  else {
    if (*(char *)((int)piVar1 + 5) != '\x03') {
      uVar4 = esp_log_timestamp();
      esp_log_write(1,&_LC0,&_L0,uVar4,&_LC0,*(undefined1 *)((int)piVar1 + 5));
      zb_buf_free_func(param_1);
      return;
    }
    uVar2 = zb_address_short_by_ieee((int)piVar1 + 6);
  }
  iVar3 = find_request_by_short(uVar2);
  if (iVar3 == 0) {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,&_LC0,&_LC9,uVar4,&_LC0,*piVar1);
  }
  else if (*piVar1 == 0) {
    if (*(int *)(iVar3 + 0x18) != 0) {
      uVar4 = esp_log_timestamp();
      esp_log_write(3,&_LC0,&_LC7,uVar4,&_LC0);
    }
  }
  else {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,&_LC0,&_LC8,uVar4,&_LC0,*piVar1);
  }
  zb_buf_free_func(param_1);
  return;
}

