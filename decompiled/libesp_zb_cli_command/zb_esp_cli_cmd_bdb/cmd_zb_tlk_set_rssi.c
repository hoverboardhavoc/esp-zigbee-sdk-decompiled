/*
 * Last changed at upstream commit d7e241034cb0adc2116988a320badb285c391de3
 * https://github.com/espressif/esp-zigbee-sdk/commit/d7e241034cb0adc2116988a320badb285c391de3
 * Upstream date: 2024-02-06 17:30:29 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.1.1(0cd72dc5)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_bdb.o -> cmd_zb_tlk_set_rssi
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void cmd_zb_tlk_set_rssi(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char *__s1;
  
  if ((param_1 != 0) && (param_2 != (undefined4 *)0x0)) {
    __s1 = (char *)*param_2;
    iVar1 = strcmp(__s1,"help");
    if (iVar1 == 0) {
      uVar2 = esp_log_timestamp();
      esp_log_write(3,0x10000,&_L0,uVar2,0x10000);
      done_or_failed(0);
      return;
    }
    iVar1 = strcmp(__s1,"get");
    if (iVar1 == 0) {
      uVar2 = esp_log_timestamp();
      uVar3 = zb_zdo_touchlink_get_rssi_threshold();
      esp_log_write(3,0x10000,&_LC100,uVar2,0x10000,uVar3);
      uVar2 = 0;
    }
    else {
      if (m_stack_is_started != '\0') {
        uVar2 = esp_log_timestamp();
        esp_log_write(1,0x10000,&_LC13,uVar2,0x10000);
        done_or_failed(0xffffffff);
        return;
      }
      if (((__s1 == (char *)0x0) || (iVar1 = atoi(__s1), iVar1 < -0x7e)) ||
         (iVar1 = atoi((char *)*param_2), 0x7e < iVar1)) {
        iVar1 = zb_zll_get_device_info();
        *(undefined4 *)(iVar1 + 0x58) = 0;
        uVar2 = esp_log_timestamp();
        esp_log_write(3,0x10000,&_LC98,uVar2,0x10000);
        uVar2 = 0xffffffff;
      }
      else {
        iVar1 = atoi((char *)*param_2);
        zb_zdo_touchlink_set_rssi_threshold((int)(char)iVar1);
        uVar2 = esp_log_timestamp();
        iVar1 = atoi((char *)*param_2);
        esp_log_write(3,0x10000,&_LC100,uVar2,0x10000,iVar1);
        uVar2 = 0;
      }
    }
    done_or_failed(uVar2);
    return;
  }
  uVar2 = esp_log_timestamp();
  esp_log_write(1,0x10000,&_LC8,uVar2,0x10000,"cmd_zb_tlk_set_rssi",0x469);
  return;
}

