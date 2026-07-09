/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> convert_esp_config_report_record_to_ezb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void convert_esp_config_report_record_to_ezb(char *param_1,char *param_2)

{
  int iVar1;
  size_t __n;
  
  memset(param_1,0,0x18);
  *param_1 = *param_2;
  *(undefined2 *)(param_1 + 2) = *(undefined2 *)(param_2 + 2);
  if (*param_2 == '\0') {
    param_1[8] = param_2[4];
    *(undefined2 *)(param_1 + 10) = *(undefined2 *)(param_2 + 6);
    *(undefined2 *)(param_1 + 0xc) = *(undefined2 *)(param_2 + 8);
    if (((*(int *)(param_2 + 0xc) != 0) &&
        (iVar1 = ezb_zcl_attr_type_is_analog(param_2[4]), iVar1 != 0)) &&
       (__n = ezb_zcl_get_attr_value_size(param_2[4],*(undefined4 *)(param_2 + 0xc)),
       (__n - 1 & 0xffff) < 8)) {
      memcpy(param_1 + 0x10,*(void **)(param_2 + 0xc),__n);
    }
  }
  else {
    *(undefined2 *)(param_1 + 8) = *(undefined2 *)(param_2 + 4);
  }
  return;
}

