/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_main.o -> aps_bind_trans_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_bind_trans_confirm(undefined4 param_1,int param_2)

{
  uint uVar1;
  undefined4 uStack_24;
  int iStack_20;
  int iStack_1c;
  uint uStack_18;
  int aiStack_14 [2];
  
  aiStack_14[0] = 0;
  zmsg_get_footer(aiStack_14,4);
  zmsg_free(param_1);
  if ((*(ushort *)(aiStack_14[0] + 0x16) & 0x20) == 0) {
    uStack_24 = 0;
    iStack_20 = 0;
    iStack_1c = 0;
    uStack_18 = 0;
    zmsg_get_footer(&uStack_24,0x10);
    if ((uStack_18 & 0xff) != 0) {
      uVar1 = (uStack_18 & 0xff) - 1;
      uStack_18 = CONCAT31(uStack_18._1_3_,(char)uVar1);
      if (param_2 != 0) {
        iStack_1c = param_2;
      }
      if ((((uVar1 & 0xff) == 0) && (iStack_20 != 0)) &&
         (param_2 = aps_bind_trans_schedule_next_nmsg(uStack_24,aiStack_14[0],&uStack_18),
         param_2 != 0)) {
        iStack_1c = param_2;
      }
      if ((uStack_18 & 0xff) != 0) {
        zmsg_update_footer(aiStack_14[0],&uStack_24,0x10);
        return;
      }
      goto _L0;
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_main.c",0x155,
                  "aps_bind_trans_confirm",
                  "!zmsg_test_flag(bind_trans.orig_msg, ((1 << ((5) % (sizeof(unsigned long) * 8)))))"
                 );
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_main.c",0x15a,
                "aps_bind_trans_confirm","bind.cnt > 0");
_L0:
  zmsg_remove_footer(aiStack_14[0],0x10);
  aps_send_data_confirm(aiStack_14[0],param_2);
  return;
}

