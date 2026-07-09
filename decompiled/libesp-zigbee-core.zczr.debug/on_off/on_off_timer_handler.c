/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> on_off.o -> on_off_timer_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void on_off_timer_handler(undefined1 *param_1)

{
  uint unaff_s1;
  int iVar1;
  uint uVar2;
  uint unaff_s2;
  uint unaff_s3;
  
  if (param_1 == (undefined1 *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/on_off.c",0x25f,
                  "on_off_timer_handler","arg != ((void *)0)");
_L0:
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/on_off.c",0x266,
                  "on_off_timer_handler","on_off_attr_desc");
  }
  else {
    unaff_s1 = on_off_srv_get_attr_desc(*param_1,0);
    unaff_s2 = on_off_srv_get_attr_desc(*param_1,0x4001);
    iVar1 = on_off_srv_get_attr_desc(*param_1,0x4002);
    if (unaff_s1 == 0) goto _L0;
    if (unaff_s2 == 0) {
      return;
    }
    if (iVar1 == 0) {
      return;
    }
    unaff_s1 = (uint)**(byte **)(unaff_s1 + 8);
    unaff_s3 = (uint)**(ushort **)(unaff_s2 + 8);
    unaff_s2 = (uint)**(ushort **)(iVar1 + 8);
    if (unaff_s1 != 0) {
      if (unaff_s3 == 0) {
        unaff_s1 = 0;
      }
      else {
        uVar2 = unaff_s3 - 1;
        unaff_s3 = uVar2 & 0xffff;
        if ((uVar2 & 0xffff) == 0) {
          unaff_s1 = 0;
        }
      }
      goto _L0;
    }
  }
  if (unaff_s2 != 0) {
    unaff_s2 = unaff_s2 - 1 & 0xffff;
  }
_L0:
  on_off_process_transition(*param_1,0x42,unaff_s1,unaff_s3,unaff_s2);
  if (unaff_s1 != 0) {
    unaff_s2 = unaff_s3;
  }
  if (unaff_s2 != 0) {
    on_off_timer_start(*param_1,100);
  }
  return;
}

