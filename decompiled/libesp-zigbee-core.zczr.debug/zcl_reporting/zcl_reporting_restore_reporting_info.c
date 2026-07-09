/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_reporting.o -> zcl_reporting_restore_reporting_info
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_reporting_restore_reporting_info(uint param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint local_30;
  uint uStack_2c;
  undefined4 uStack_28;
  undefined1 uStack_24;
  undefined2 uStack_23;
  undefined1 uStack_21;
  undefined1 uStack_20;
  undefined2 uStack_1f;
  undefined1 uStack_1d;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  local_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_23 = 0;
  uStack_21 = 0;
  uStack_20 = 0;
  uStack_1f = 0;
  uStack_1d = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  ds_zcl_reporting_info_itor_read(&local_30);
  do {
    if (uStack_14._2_1_ != '\0') {
      return 0;
    }
    if ((local_30 >> 8 & 0xff) == param_1) {
      iVar2 = zcl_reporting_info_create
                        (local_30 >> 0x10,(char)local_30 != '\0',uStack_2c & 0xffff,
                         uStack_2c >> 0x10 & 0xff,uStack_2c >> 0x18 | (uStack_28 & 0xff) << 8,
                         uStack_28 >> 8 & 0xffff);
      if (iVar2 == 0) {
        uVar1 = 1;
_L0:
        zcl_reporting_refresh_stored_reporting_info();
        return uVar1;
      }
      if ((char)local_30 == '\0') {
        *(ushort *)(iVar2 + 0x10) = CONCAT11(uStack_24,uStack_28._3_1_);
        *(undefined2 *)(iVar2 + 0x12) = uStack_23;
        *(ushort *)(iVar2 + 0x28) = CONCAT11(uStack_20,uStack_21);
        *(undefined2 *)(iVar2 + 0x2a) = uStack_1f;
        *(undefined1 *)(iVar2 + 0x18) = uStack_1d;
        *(undefined1 *)(iVar2 + 0x19) = (undefined1)uStack_1c;
        *(undefined1 *)(iVar2 + 0x1a) = uStack_1c._1_1_;
        *(undefined1 *)(iVar2 + 0x1b) = uStack_1c._2_1_;
        *(undefined1 *)(iVar2 + 0x1c) = uStack_1c._3_1_;
        *(undefined1 *)(iVar2 + 0x1d) = (undefined1)uStack_18;
        *(undefined1 *)(iVar2 + 0x1e) = uStack_18._1_1_;
        *(undefined1 *)(iVar2 + 0x1f) = uStack_18._2_1_;
      }
      else {
        *(ushort *)(iVar2 + 0x10) = CONCAT11(uStack_24,uStack_28._3_1_);
      }
      iVar2 = zcl_reporting_info_add();
      if (iVar2 != 0) {
        uVar1 = 0xffffffff;
        goto _L0;
      }
    }
    ds_zcl_reporting_info_next(&local_30);
  } while( true );
}

