/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_common.o -> zcl_attr_value_is_changed
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint zcl_attr_value_is_changed(int param_1,void *param_2)

{
  size_t __n;
  size_t sVar1;
  uint uVar2;
  int iVar3;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  if (param_1 != 0) {
    if (param_2 == (void *)0x0) {
      return 0;
    }
    __n = zcl_get_attr_value_size(*(undefined1 *)(param_1 + 2),*(undefined4 *)(param_1 + 8));
    sVar1 = zcl_get_attr_value_size(*(undefined1 *)(param_1 + 2),param_2);
    if (__n == 0xffff) {
      return 0;
    }
    if (sVar1 == 0xffff) {
      return 0;
    }
    uVar2 = zcl_attr_type_is_composite(*(undefined1 *)(param_1 + 2));
    if (uVar2 != 0) {
      if (__n != sVar1) {
        return uVar2;
      }
      iVar3 = memcmp(*(void **)(param_1 + 8),param_2,__n);
      return (uint)(iVar3 != 0);
    }
    uStack_28 = 0;
    uStack_24 = 0;
    if (__n == sVar1) {
      zcl_write_attr_value(&uStack_28,param_2,*(undefined1 *)(param_1 + 2));
      iVar3 = memcmp(*(void **)(param_1 + 8),&uStack_28,__n);
      return (uint)(iVar3 != 0);
    }
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_common.c",0x1f7,
                  "zcl_attr_value_is_changed","old_size == new_size");
  }
  return 0;
}

