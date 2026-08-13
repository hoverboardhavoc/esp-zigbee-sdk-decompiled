/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_packet.o -> zdo_packet_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zdo_packet_send(char *param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  uint uStack_1c;
  code *pcStack_18;
  char *pcStack_14;
  
  if (param_1 == (char *)0x0) {
_L0:
    iVar5 = 0x80;
    pcVar4 = param_1;
  }
  else {
    uVar2 = zdo_packet_max_available_space(*(undefined2 *)(param_1 + 6));
    uVar3 = zmsg_get_length(*(undefined4 *)(param_1 + 0x14));
    if (uVar2 < uVar3) {
      pcVar4 = (char *)0x0;
      iVar5 = 0x8a;
      goto _L0;
    }
    if (*(short *)(param_1 + 6) < 0) {
      if (param_1[8] != '\0') {
        __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_packet.c",0x1e2,
                      "zdo_packet_send","packet->ctx.mode == ZDO_NONE_RSP");
        goto _L0;
      }
    }
    else {
      iVar5 = core_globals_get();
      cVar1 = *(char *)(iVar5 + 0xca8);
      *(char *)(iVar5 + 0xca8) = cVar1 + '\x01';
      *param_1 = cVar1;
    }
    zmsg_prepend_bytes(*(undefined4 *)(param_1 + 0x14),1,param_1);
    local_50 = *(undefined4 *)(param_1 + 8);
    uStack_4c = *(undefined4 *)(param_1 + 0xc);
    uStack_48 = *(undefined4 *)(param_1 + 0x10);
    pcVar4 = (char *)zdo_packet_ctx_create_entry(*param_1,&local_50);
    if (pcVar4 == (char *)0x0) {
      iVar5 = 0x8a;
    }
    else if ((pcVar4[0x18] == '\0') || (iVar5 = zdo_packet_ctx_list_add_entry(), iVar5 == 0)) {
      uStack_34 = 0;
      uStack_30 = 0;
      uStack_2c = 0;
      uStack_28 = 0;
      uStack_24 = 0;
      uStack_20 = 0;
      uStack_1c = 0;
      pcStack_18 = (code *)0x0;
      pcStack_14 = (char *)0x0;
      uStack_34 = zdo_packet_transfer_ownership(param_1);
      uStack_30 = CONCAT31(uStack_30._1_3_,2);
      uStack_30 = CONCAT22(*(undefined2 *)(param_1 + 2),(undefined2)uStack_30);
      uStack_24 = CONCAT22(uStack_24._2_2_,*(undefined2 *)(param_1 + 6));
      uStack_1c = uStack_1c | 2;
      pcStack_18 = zdo_packet_cnf_handler;
      pcStack_14 = pcVar4;
      af_data_request(&uStack_34);
      iVar5 = ezb_err_to_zdp_status();
      if (iVar5 == 0) {
        return 0;
      }
    }
  }
_L0:
  zdo_packet_ctx_free_entry_direct(pcVar4);
  return iVar5;
}

