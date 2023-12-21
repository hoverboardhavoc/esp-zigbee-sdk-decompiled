/*
 * Last changed at upstream commit 790bc8d6ece1bf5f739debaa4aa4af508982070a
 * https://github.com/espressif/esp-zigbee-sdk/commit/790bc8d6ece1bf5f739debaa4aa4af508982070a
 * Upstream date: 2023-12-21 19:52:25 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.7(bdde218a)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_bdb.o -> cmd_zb_role
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void cmd_zb_role(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint auStack_14 [4];
  
  iVar1 = zb_role_check();
  if (iVar1 != 3) {
    if (m_stack_is_started != '\0') {
      uVar2 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC19,uVar2,0x10000);
      return;
    }
    if (iVar1 != 0) {
      if (iVar1 != 1) {
        uVar2 = esp_log_timestamp();
        esp_log_write(1,0x10000,&_LC3,uVar2,0x10000);
        return;
      }
      m_default_role = 1;
      uVar2 = esp_log_timestamp();
      esp_log_write(3,0x10000,&_LC45,uVar2,0x10000);
      return;
    }
    m_default_role = 0;
    uVar2 = esp_log_timestamp();
    esp_log_write(3,0x10000,&_LC44,uVar2,0x10000);
    return;
  }
  uVar3 = zb_get_network_role();
  if (uVar3 == 2) {
    auStack_14[0] = 0x64657a;
    goto _L0;
  }
  if (uVar3 < 3) {
    if (uVar3 == 0) {
      auStack_14[0] = 0x637a;
      goto _L0;
    }
    if (uVar3 != 1) goto _L0;
  }
  else if (uVar3 != 3) goto _L0;
  auStack_14[0] = 0x727a;
_L0:
  auStack_14[0] = auStack_14[0] & 0xffffff;
  uVar2 = esp_log_timestamp();
  esp_log_write(3,0x10000,&_LC18,uVar2,0x10000,auStack_14);
  return;
}

