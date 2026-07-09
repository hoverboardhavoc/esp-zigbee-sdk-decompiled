/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zdo_packet.o -> zdo_packet_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zdo_packet_send(char *param_1)

{
  char cVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uStack_44;
  undefined1 auStack_40 [2];
  undefined2 uStack_3e;
  undefined2 uStack_34;
  undefined1 uStack_2c;
  code *pcStack_28;
  char *pcStack_24;
  
  if (param_1 == (char *)0x0) {
_L0:
    iVar3 = 0x80;
  }
  else {
    uVar4 = zdo_packet_max_available_space(*(undefined2 *)(param_1 + 6));
    uVar5 = zmsg_get_length(*(undefined4 *)(param_1 + 0x14));
    if (uVar5 <= uVar4) {
      if (*(short *)(param_1 + 6) < 0) {
        if (param_1[8] != '\0') {
          __assert_func(0,0,0,0);
          goto _L0;
        }
      }
      else {
        iVar3 = core_globals_get();
        cVar1 = *(char *)(iVar3 + 0xca8);
        *(char *)(iVar3 + 0xca8) = cVar1 + '\x01';
        *param_1 = cVar1;
      }
      zmsg_prepend_bytes(*(undefined4 *)(param_1 + 0x14),1,param_1);
      cVar1 = *param_1;
      cVar2 = param_1[8];
      uVar8 = *(undefined4 *)(param_1 + 0xc);
      uVar7 = *(undefined4 *)(param_1 + 0x10);
      pcVar6 = (char *)calloc(1,0x28);
      if (pcVar6 != (char *)0x0) {
        *(undefined4 *)(pcVar6 + 0x20) = uVar7;
        *pcVar6 = cVar1;
        pcVar6[0x18] = cVar2;
        *(undefined4 *)(pcVar6 + 0x1c) = uVar8;
        pcVar6[0x14] = pcVar6[0x14] & 0xfc;
        *(char **)(pcVar6 + 0x24) = pcVar6 + 0x24;
        if (cVar2 != '\0') {
          uVar4 = nwk_pim_get_fast_poll_interval();
          nwk_pim_start_fast_poll(5000 / uVar4);
          iVar3 = core_globals_get();
          *(undefined4 *)(pcVar6 + 0x24) = *(undefined4 *)(iVar3 + 0xcac);
          *(char **)(iVar3 + 0xcac) = pcVar6 + 0x24;
          milli_timer_init(zdo_packet_ctx_entry_timeout,pcVar6);
          milli_timer_start(pcVar6 + 4,5000);
        }
        memset(auStack_40,0,0x18);
        uStack_44 = *(undefined4 *)(param_1 + 0x14);
        param_1[0x14] = '\0';
        param_1[0x15] = '\0';
        param_1[0x16] = '\0';
        param_1[0x17] = '\0';
        auStack_40[0] = 2;
        uStack_3e = *(undefined2 *)(param_1 + 2);
        uStack_34 = *(undefined2 *)(param_1 + 6);
        uStack_2c = 2;
        pcStack_28 = zdo_packet_cnf_handler;
        pcStack_24 = pcVar6;
        af_data_request(&uStack_44);
        iVar3 = ezb_err_to_zdp_status();
        if (iVar3 == 0) {
          return 0;
        }
        milli_timer_stop(pcVar6 + 4);
        mm_free(pcVar6);
        return iVar3;
      }
    }
    iVar3 = 0x8a;
  }
  return iVar3;
}

