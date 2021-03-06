/** Copyright 2020 RWTH Aachen University. All rights reserved.
 *
 *  Licensed under the RWTH ASR License (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.hltpr.rwth-aachen.de/rwth-asr/rwth-asr-license.html
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */
#include <Am/Module.hh>
#include <Bliss/Lexicon.hh>
#include <Core/Application.hh>
#include <Flow/Module.hh>
#include <Flow/Registry.hh>
#include <Fsa/Compose.hh>
#include <Fsa/Output.hh>
#include <Lm/Module.hh>
#include <Speech/ModelCombination.hh>
#include <Speech/Module.hh>

class TestApplication : Core::Application {
public:
    std::string getUsage() const {
        return "short program to test speech toolkit\n";
    }

    int main(const std::vector<std::string>& arguments) {
        INIT_MODULE(Lm)
        INIT_MODULE(Am)
        INIT_MODULE(Flow)
        INIT_MODULE(Speech)
        Flow::Registry::instance().dumpFilters(clog());
        return 0;
    }
};

APPLICATION(TestApplication)
