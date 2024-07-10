pipeline {
	agent {
		label 'gespage-win-builder'
	}
	stages {
		stage("Checkout-agent") {
			steps {
			    bat 'if not exist agent mkdir QtUnitTestProject'
			    dir("QtUnitTestProject") {
					script {
						def scmVars = checkout([
							$class: 'GitSCM', 
							branches: [[name: "master"]], 
							userRemoteConfigs: [[url: 'https://github.com/danguyencarta/QtUnitTestProject.git']]
						])
					}
				}
			}
			post {
				success {echo 'checkout agent was done successfully'}
				failure {echo 'There is a problem in agent checkout'}
			}
		}
	}
}