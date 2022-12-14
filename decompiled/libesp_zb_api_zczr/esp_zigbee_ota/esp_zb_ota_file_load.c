/*
 * Last changed at upstream commit dfdf370f9265e944dde2de8bee7a248c7515f1ef
 * https://github.com/espressif/esp-zigbee-sdk/commit/dfdf370f9265e944dde2de8bee7a248c7515f1ef
 * Upstream date: 2022-12-14 19:24:05 +0800
 * Upstream subject: examples:Add ota application example(986c075)
 * Source: libesp_zb_api_zczr -> esp_zigbee_ota.o -> esp_zb_ota_file_load
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void esp_zb_ota_file_load(undefined1 *param_1)

{
  _DAT_000102f0 = 0xbeef11e;
  _DAT_000102f4 = 0x100;
  _DAT_000102f6 = 0x38;
  _DAT_000102f8 = 0x10;
  _DAT_000102fa = *(undefined2 *)(param_1 + 8);
  _DAT_000102fc = *(undefined2 *)(param_1 + 10);
  _DAT_000102fe = (short)*(undefined4 *)(param_1 + 0xc);
  _DAT_00010300 = (short)((uint)*(undefined4 *)(param_1 + 0xc) >> 0x10);
  _DAT_00010302 = 2;
  _DAT_00010304 = 0;
  _DAT_00010308 = 0;
  _DAT_0001030c = 0;
  _DAT_00010310 = 0;
  _DAT_00010314 = 0;
  _DAT_00010318 = 0;
  _DAT_0001031c = 0;
  _DAT_00010320 = 0;
  _DAT_00010324 = *(int *)(param_1 + 0x10) + 0x38;
  DAT_00010328 = *(undefined4 *)(param_1 + 0x14);
  ota_config = *param_1;
  DAT_000102ec = *(undefined4 *)(param_1 + 4);
  return;
}

