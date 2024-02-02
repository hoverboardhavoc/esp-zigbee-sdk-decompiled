/*
 * Last changed at upstream commit f9cc2dccd1062ffdf8f9e034d227fe83c0a1712e
 * https://github.com/espressif/esp-zigbee-sdk/commit/f9cc2dccd1062ffdf8f9e034d227fe83c0a1712e
 * Upstream date: 2024-02-02 22:17:34 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.1.0(5362d771)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_bdb.o -> cmd_zb_tlk_set_master_key
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void cmd_zb_tlk_set_master_key(int param_1,undefined4 *param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  char *__s1;
  int iVar4;
  size_t sVar5;
  undefined4 uVar6;
  undefined1 uStack_50;
  undefined1 uStack_4f;
  undefined1 uStack_4e;
  
  if ((param_1 == 0) || (param_2 == (undefined4 *)0x0)) {
    uVar6 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC8,uVar6,0x10000,"cmd_zb_tlk_set_master_key",0x48a);
  }
  else {
    __s1 = (char *)*param_2;
    iVar4 = strcmp(__s1,"help");
    if (iVar4 == 0) {
      uVar6 = esp_log_timestamp();
      esp_log_write(3,0x10000,&_L0,uVar6,0x10000);
      done_or_failed(0);
    }
    else {
      iVar4 = strcmp(__s1,"get");
      if (iVar4 == 0) {
        uVar6 = esp_log_timestamp();
        iVar4 = zb_zll_get_device_info();
        uVar1 = *(undefined1 *)(iVar4 + 0x14);
        iVar4 = zb_zll_get_device_info();
        uVar2 = *(undefined1 *)(iVar4 + 0x15);
        iVar4 = zb_zll_get_device_info();
        uVar3 = *(undefined1 *)(iVar4 + 0x16);
        zb_zll_get_device_info();
        zb_zll_get_device_info();
        zb_zll_get_device_info();
        zb_zll_get_device_info();
        zb_zll_get_device_info();
        zb_zll_get_device_info();
        zb_zll_get_device_info();
        zb_zll_get_device_info();
        zb_zll_get_device_info();
        zb_zll_get_device_info();
        zb_zll_get_device_info();
        zb_zll_get_device_info();
        zb_zll_get_device_info();
        esp_log_write(3,0x10000,&_LC102,uVar6,0x10000,uVar1,uVar2,uVar3);
        uVar6 = 0;
      }
      else {
        if (m_stack_is_started != '\0') {
          uVar6 = esp_log_timestamp();
          esp_log_write(1,0x10000,&_LC13,uVar6,0x10000);
          done_or_failed(0xffffffff);
          return;
        }
        sVar5 = strlen(__s1);
        if (sVar5 == 0x20) {
          iVar4 = parse_hex_str(__s1,0x20,&uStack_50,0x10,0);
          if (iVar4 == 0) {
            uVar6 = esp_log_timestamp();
            esp_log_write(1,0x10000,&_LC82,uVar6,0x10000);
            uVar6 = 0xffffffff;
          }
          else {
            zb_zdo_touchlink_set_master_key(&uStack_50);
            uVar6 = esp_log_timestamp();
            esp_log_write(3,0x10000,&_LC103,uVar6,0x10000,uStack_50,uStack_4f,uStack_4e);
            uVar6 = esp_log_timestamp();
            esp_log_write(3,0x10000,&_LC1,uVar6,0x10000);
            uVar6 = 0;
          }
        }
        else {
          uVar6 = esp_log_timestamp();
          esp_log_write(1,0x10000,&_LC76,uVar6,0x10000);
          uVar6 = 0xffffffff;
        }
      }
      done_or_failed(uVar6);
    }
  }
  return;
}

