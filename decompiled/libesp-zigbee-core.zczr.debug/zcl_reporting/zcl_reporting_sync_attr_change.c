/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_reporting.o -> zcl_reporting_sync_attr_change
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_reporting_sync_attr_change(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((param_1 != 0) &&
     (iVar1 = zcl_get_attr_desc(*(undefined1 *)(param_1 + 1),*(undefined2 *)(param_1 + 4),
                                *(undefined1 *)(param_1 + 8),*(undefined2 *)(param_1 + 6),
                                *(undefined2 *)(param_1 + 0x30)), iVar1 != 0)) {
    iVar2 = zcl_attr_type_is_analog(*(undefined1 *)(iVar1 + 2));
    if (iVar2 == 0) {
      iVar2 = zcl_get_attr_value_size(*(undefined1 *)(iVar1 + 2),*(undefined4 *)(iVar1 + 8));
      if (iVar2 == 0xffff) {
        *(undefined4 *)(param_1 + 0x20) = 0;
      }
      else {
        uVar3 = crc32_next(0,*(undefined4 *)(iVar1 + 8),iVar2);
        *(undefined4 *)(param_1 + 0x20) = uVar3;
      }
    }
    else {
      zcl_read_attr_value(param_1 + 0x20,*(undefined4 *)(iVar1 + 8),*(undefined1 *)(iVar1 + 2));
    }
    *(byte *)(param_1 + 9) =
         (byte)((*(uint *)(param_1 + 8) >> 0xc & 0xe) << 4) | *(byte *)(param_1 + 9) & 0xf;
  }
  return;
}

