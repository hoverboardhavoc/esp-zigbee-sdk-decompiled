/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> ota_upgrade_cli.o -> ota_upgrade_download_stop_retry.part.0
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ota_upgrade_download_stop_retry_part_0(void)

{
  int iVar1;
  
  __assert_func(0,0,0,0);
  iVar1 = ota_upgrade_cli_get_attr_desc_part_0();
  if (iVar1 == 0) {
    iVar1 = ota_upgrade_download_stop_retry_part_0();
  }
  return *(undefined4 *)(iVar1 + 8);
}

