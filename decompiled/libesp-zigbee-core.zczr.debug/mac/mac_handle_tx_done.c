/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_handle_tx_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_handle_tx_done(int param_1,undefined4 param_2,undefined1 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  char *extraout_a1;
  int iStack_58;
  undefined2 uStack_54;
  undefined2 uStack_52;
  undefined2 uStack_50;
  undefined2 uStack_4e;
  undefined2 uStack_4c;
  undefined2 uStack_4a;
  undefined2 uStack_48;
  undefined2 uStack_46;
  undefined2 uStack_44;
  undefined1 uStack_42;
  undefined1 uStack_3d;
  undefined2 uStack_3c;
  undefined2 uStack_3a;
  undefined2 uStack_38;
  undefined2 uStack_36;
  undefined2 uStack_34;
  undefined2 uStack_2e;
  undefined2 uStack_2c;
  undefined2 uStack_2a;
  undefined2 uStack_28;
  ushort uStack_24;
  char cStack_21;
  
  iVar1 = zmsg_queue_get_head(param_2);
  if (iVar1 != 0) {
    uStack_3d = 0;
    zmsg_queue_dequeue(param_2,iVar1);
    if (param_4 != 0) {
      zmsg_remove_footer(iVar1,10);
    }
    iVar2 = parse_mhr_from_msg(iVar1,&uStack_3c,&uStack_3d);
    if (iVar2 == 0) {
      zmsg_remove_header(iVar1,uStack_3d);
      if (cStack_21 != '\x02') {
        if ((uStack_24 & 7) == 1) {
          uStack_54 = CONCAT11(uStack_54._1_1_ & 0xfe | (byte)param_4 & 1,param_3);
          iStack_58 = iVar1;
          nwk_mm_data_confirm(*(undefined1 *)(param_1 + 0x2c),&iStack_58);
          return;
        }
        iVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac.c",0x4ed,
                              "mac_handle_tx_done",
                              "mac_fcf_get_frame_type(mhr.fcf) == MAC_FRAME_DATA");
        if (*extraout_a1 == '\0') {
          while (iVar2 = zmsg_queue_get_head(iVar1 + 0x48), iVar2 != 0) {
            mac_handle_tx_done(iVar1,iVar1 + 0x48,0xda,0);
          }
          while (iVar2 = zmsg_queue_get_head(iVar1 + 0x54), iVar2 != 0) {
            mac_handle_tx_done(iVar1,iVar1 + 0x54,0xda,1);
          }
          while (iVar2 = zmsg_queue_get_head(iVar1 + 0x60), iVar2 != 0) {
            mac_handle_tx_done(iVar1,iVar1 + 0x60,0xda,1);
          }
          micro_timer_stop(iVar1 + 0x6c);
        }
        return;
      }
    }
    else {
      __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac.c",0x4dd,
                    "mac_handle_tx_done","(parse_mhr_from_msg(msg, &mhr, &mhr_len)) == 0");
    }
    uStack_54 = uStack_2e;
    uStack_52 = uStack_2c;
    uStack_50 = uStack_2a;
    uStack_4e = uStack_3c;
    uStack_4c = uStack_3a;
    uStack_4a = uStack_38;
    uStack_48 = uStack_36;
    uStack_46 = uStack_34;
    uStack_44 = uStack_28;
    uStack_42 = param_3;
    nwk_mm_comm_status_indication(*(undefined1 *)(param_1 + 0x2c),&iStack_58);
    zmsg_free(iVar1);
  }
  return;
}

