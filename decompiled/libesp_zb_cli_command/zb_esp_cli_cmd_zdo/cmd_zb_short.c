/*
 * Last changed at upstream commit 8f416d47159477fb2dfe72f817700bc25debb587
 * https://github.com/espressif/esp-zigbee-sdk/commit/8f416d47159477fb2dfe72f817700bc25debb587
 * Upstream date: 2023-03-20 14:23:27 +0800
 * Upstream subject: zcl: support more ZCL cluster(caef391)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zdo.o -> cmd_zb_short
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void cmd_zb_short(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_18 [16];
  
  zb_get_long_address(auStack_18);
  iVar1 = zb_address_short_by_ieee(auStack_18);
  if (iVar1 == 0xffff) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,&_LC3,&_LC54,uVar2,&_LC3);
  }
  else {
    uVar2 = esp_log_timestamp();
    esp_log_write(3,&_LC3,&_LC53,uVar2,&_LC3,iVar1);
    uVar2 = esp_log_timestamp();
    esp_log_write(3,&_LC3,&_LC7,uVar2,&_LC3);
  }
  return;
}

